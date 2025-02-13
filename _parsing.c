# define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

struct 				_parsing {
	char			**map;
	unsigned int	width, height;
	unsigned int	nb_coin;
	unsigned int	nb_exit;	
	unsigned int	nb_player;
	unsigned int	nb_collectible;
};

struct _parsing					*parsingError(char **const error, const char *const format, ...) {
	va_list						args;

	va_start(args, format);
	vasprintf(error, format, args);
	va_end(args);
	return NULL;
}

static int						caseHandleLimitOne(struct _parsing *const parsing, char **const error, const char c) {

	if (c == 'P' || c == 'p') {
		if (parsing->nb_player) {
			parsingError(error, "player cannot be redefined");
			return 1;
		}
		parsing->nb_player = 1;
	}
	else if (c == 'e' || c == 'E') {
		if (parsing->nb_exit) {
			parsingError(error, "exit cannot be redefined");
			return 1;
		}
		parsing->nb_exit = 1;
	}
	return 0;
}
static int						caseHandleCollectible(struct _parsing *const parsing, char **const error, const char c) {
	parsing->nb_collectible++;
	return 0;
}
static int						caseHandleSuccess(struct _parsing *const parsing, char **const error, const char c) {
	return 0;
}

struct _parsing					*parseBerFile(const char *const file, struct _parsing *const parsing, char **const error) {

	const int					fd = open(file, O_RDONLY);
	struct stat					fdStats;
	char						*content, *origin;
	int							w, h;
	int							(*handler)(struct _parsing *const, char **const, const char);

	static int					(*const _cases[256])(struct _parsing *const, char **const, const char) = {
		['0'] = caseHandleSuccess,
		['1'] = caseHandleSuccess,
		['C'] = caseHandleCollectible, ['c'] = caseHandleCollectible,
		['E'] = caseHandleLimitOne, ['e'] = caseHandleLimitOne,
		['P'] = caseHandleLimitOne, ['p'] = caseHandleLimitOne
	};

	if (fd < 0)
		return parsingError(error, "open: %s\n", strerror(errno));
	if (fstat(fd, &fdStats) < 0)
		return parsingError(error, "fstat: %s", strerror(errno));
	content = malloc((size_t)fdStats.st_size + 1);
	content[fdStats.st_size] = 0;
	origin = content;
	if (read(fd, content, fdStats.st_size) != fdStats.st_size) {
		free(content);
		return parsingError(error, "read: %s", strerror(errno));
	}

	// new function
	while (*content) {
		if (!_cases[*content])
			return parsingError(error, "illegal char at beginning of line: %c", *content);
		w = 0;
		while ((handler = _cases[*content])) {
			if (handler(parsing, error, *content))
				return NULL;
			w++;
			content++;
		}
		if (!_cases[*content] && *content != '\n' && *content)
			return parsingError(error, "illegal char in line declaration: %c", *content);
		if (parsing->width && parsing->width != w)
			return parsingError(error, "invalid number of char per line find %u having: %u", w, parsing->width);
		else
			parsing->width = w;
		h++;
		if (*content == '\n')
			content++;
	}
	if (w < 3 || h < 3)
		return parsingError(error, "map cannot have size of zero having: %u, %u", w, h);
	parsing->height = h;
	if (parsing->nb_collectible < 1)
		return parsingError(error, "collectible must be at less 1");
	// player
	// exit
	// ==0

	// new function	
	int	x, y;

	parsing->map = malloc(sizeof(char*) * h);
	y = 0;
	while (y < h)
		parsing->map[y++] = malloc(sizeof(char) * w);
	content = origin;
	y = 0;
	while (*content) {
		x = 0;
		while (_cases[*content])
			parsing->map[y][x++] = *content++;
		if (*content == '\n')
			content++;
		y++;
	}

	return parsing;
}

int					main(int argc, char **argv) {

	struct _parsing	parsing;
	char			*error;
	int				x, y;

	bzero(&parsing, sizeof(struct _parsing));
	error = NULL;
	if (*++argv) {
		if (!(parseBerFile(*argv, &parsing, &error))) {
			dprintf(STDERR_FILENO, "parsing: %s\n", error);
			free(error);
			return EXIT_FAILURE;
		}
		y = 0;
		while (y < parsing.height)
		{
			x = 0;
			while (x < parsing.width) {
				write(STDOUT_FILENO, parsing.map[y] + x, 1);
				x++;
			}
			write(STDOUT_FILENO, "\n", 1);
			y++;
		}
		printf("player: %u\ncollectible: %u\nexit: %u\n", parsing.nb_player, parsing.nb_collectible, parsing.nb_exit);
	}
}
