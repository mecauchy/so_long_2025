/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:43:26 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/12 16:35:21 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// char	*new_line(char *next_str)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (!next_str)
// 		return (NULL);
// 	while (next_str[i] && next_str[i] != '\n')
// 		i++;
// 	if (!next_str[i])
// 	{
// 		free(next_str);
// 		return (NULL);
// 	}
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - i + 1));
// 	if (!str)
// 		return (free(next_str), NULL);
// 	i++;
// 	j = 0;
// 	while (next_str[i])
// 		str[j++] = next_str[i++];
// 	str[j] = '\0';
// 	free(next_str);
// 	return (str);
// }

// char	*ft_get_line(char *next_str)
// {
// 	int		i;
// 	char	*new_line;

// 	i = 0;
// 	if (!next_str || !next_str[i])
// 		return (NULL);
// 	while (next_str[i] != '\n' && next_str[i])
// 		i++;
// 	new_line = (char *)malloc(sizeof(char) * i + 2);
// 	if (!new_line)
// 		return (NULL);
// 	i = 0;
// 	while (next_str[i] != '\n' && next_str[i])
// 	{
// 		new_line[i] = next_str[i];
// 		i++;
// 	}
// 	if (next_str[i] && next_str[i] == '\n')
// 	{
// 		new_line[i] = next_str[i];
// 		i++;
// 	}
// 	new_line[i] = '\0';
// 	return (new_line);
// }

// char	*read_to_next_str(char *next_str, int fd)
// {
// 	int		rd_bytes;
// 	char	*buff;

// 	rd_bytes = 1;
// 	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!buff)
// 		return (NULL);
// 	while ((!ft_find_newline(next_str)) && rd_bytes > 0)
// 	{
// 		rd_bytes = read(fd, buff, BUFFER_SIZE);
// 		if ((rd_bytes == -1) || (rd_bytes == 0 && next_str == NULL))
// 		{
// 			free(next_str);
// 			next_str = NULL;
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[rd_bytes] = '\0';
// 		next_str = ft_strjoin(next_str, buff);
// 	}
// 	free(buff);
// 	return (next_str);
// }

// static char	*next_str = NULL;

// char	*get_next_line(int fd)
// {
// 	char		*ret;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	next_str = read_to_next_str(next_str, fd);
// 	if (!next_str)
// 		return (NULL);
// 	ret = ft_get_line(next_str);
// 	if (!ret && next_str && *next_str != '\0')
// 	{
// 		ret = ft_strdup(next_str);
// 		free(next_str);
// 		next_str = NULL;
// 	}
// 	else
// 		next_str = new_line(next_str);
// 	return (ret);
// }

char	*get_line(char **backup, char **line)
{
	char	*next_backup;
	int		i;

	i = 0;
	next_backup = NULL;
	while (*(*backup + i) != '\n' && *(*backup + i) != '\0')
		i++;
	if (*(*backup + i) == '\n')
	{
		i++;
		*line = ft_substr(*backup, 0, i);
		next_backup = ft_strdup(*backup + i);
	}
	else
		*line = ft_strdup(*backup);
	ft_free_ptr(backup);
	return (next_backup);
}

int	read_line(int fd, char **buffer, char **backup, char **line)
{
	int		bytes_read;
	char	*temporary;

	bytes_read = 1;
	while (!ft_strchr(*backup, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temporary = *backup;
		*backup = ft_strjoin(temporary, *buffer);
		free(temporary);
	}
	ft_free_ptr(buffer);
	*backup = get_line(backup, line);
	if (!(**line))
		ft_free_ptr(line);
	return (bytes_read);
}


char	*get_next_line(int fd)
{
	static char	*buffer_backup = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	if (!read_line(fd, &buffer, &buffer_backup, &line) && !line)
		return (NULL);
	return (line);
}

void	ft_free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
