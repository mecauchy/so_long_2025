/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:24:03 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 14:38:46 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

// ---------------------------------------------------------------------------
//				LIBFT
// ---------------------------------------------------------------------------

int		ft_isalpha(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// ---------------------------------------------------------------------------
//				GET NEXT LINE
// ---------------------------------------------------------------------------

char	*get_line(char **backup, char **line);
int		read_line(int fd, char **buffer, char **backup, char **line);
char	*get_next_line(int fd);
void	ft_free_ptr(char **ptr);

// ---------------------------------------------------------------------------
//				FT PRINTF
// ---------------------------------------------------------------------------

int		ft_printf(const char *format, ...);
int		ft_print_exec(va_list arg, char *format);
int		ft_search_s(va_list arg);
int		ft_search_c(va_list arg);
int		ft_search_p(va_list arg);
int		ft_search_d_i(va_list arg);
int		ft_search_u(va_list arg);
int		ft_search_x(va_list arg);
int		ft_search_xx(va_list arg);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hex_x(unsigned int nb);
int		ft_putnbr_hex_xx(unsigned int nb);
int		ft_putnbr_hex_p(unsigned long p);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);

#endif
