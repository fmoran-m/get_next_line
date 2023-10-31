/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:47:59 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/31 19:46:01 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_intro(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *file)
{
	char	*buf;
	char	*temp;
	ssize_t	buf_read;

	if (!file)
		file = ft_strdup("");
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free_file(&file));
	buf_read = 1;
	while (buf_read > 0 && !is_intro(buf))
	{
		buf_read = read(fd, buf, BUFFER_SIZE);
		if (buf_read == -1)
			return (free(buf), free_file(&file));
		buf[buf_read] = 0;
		temp = ft_strjoin(file, buf);
		if (!temp)
			return (free (buf), free_file(&file));
		free (file);
		file = temp;
	}
	free (buf);
	return (file);
}

char	*new_line(char *file)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!file[i])
		return (file);
	i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = file[j];
		j++;
	}
	return (line);
}

char	*new_file(char *file, char *line)
{
	char	*str;
	int		i;
	int		j;

	if (!is_intro(file))
		return (NULL);
	i = ft_strlen(file);
	j = ft_strlen(line);
	str = (char *)ft_calloc((i - j) + 2, sizeof(char));
	if (!str)
		return (free_file(&file));
	i = 0;
	while (file[j])
	{
		str[i] = file[j];
		i++;
		j++;
	}
	free_file(&file);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*file[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file[fd] = read_line(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	if (!*file[fd])
		return (free_file(&file[fd]));
	line = new_line(file[fd]);
	if (!line)
		return (free_file(&file[fd]));
	file[fd] = new_file(file[fd], line);
	return (line);
}
