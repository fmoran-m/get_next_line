/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:50 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/25 19:16:21 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*new_line(char *line)
{
	char	*str;
    int		i;
    int		j;

	if (!line)
		return (NULL);
    if (!is_intro(line))
		return (line);
	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	if (line[i] == 0)
		return (line);
	str = (char *)ft_calloc((i + 2), sizeof(char));
	if (!str)
		return (free (line), NULL);
    while (j <= i)
	{
		str[j] = line[j]; 
		j++;
    }
	free (line);
	return (str);
}

char	*read_line(int fd, char *file)
{
	char	*buf;
	char	*line;
	ssize_t	buf_read;

	line = ft_strdup(file);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (free (line), NULL);
	buf_read = 1;
	while (buf_read > 0 && !is_intro(buf))
	{
		buf_read = read(fd, buf, BUFFER_SIZE);
		if (buf_read == -1)
			return (free(buf), free(line), NULL);
		buf[buf_read] = 0;
		if (buf_read > 0)
		{
			line = ft_strjoin(line, buf);
			if (!line)
				return (free (buf), NULL);
		}
    }
    free (buf);
    return (line);
}

char	*new_file(char *line, char* file)
{
    int		i;
    int		j;
    char	*str;

	if (!is_intro(line))
		return (free(file), NULL);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
		i++;
    while (line[j] != '\n')
		j++;
	str = (char *)ft_calloc((i - j) + 2, sizeof(char));
	if (!str)
		return (free(str), free(file), NULL); 
	j++;
	if (!line[j])//Esto es para controlar que el siguiente al salto de línea no sea nulo
		return (free(str), free(file), NULL);
	i = 0;
    while (line[j])
    {
		str[i] = line[j];
		i++;
		j++;
	}
	str[i] = 0;
	free (file);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    line = read_line(fd, file); 
    file = new_file(line, file);
    line = new_line(line);
    return (line);
}
/*
int main (void)
{
    char    *a;
    int fd = open("test.txt", O_RDONLY);
    a = get_next_line(fd);
    while (a != NULL)
    {
	printf("%s", a);
	free (a);
	a = get_next_line(fd);
    }
    close (fd);
    return 0;
}
*/
