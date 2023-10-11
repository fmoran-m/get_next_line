/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:50 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/11 21:32:08 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*real_buf(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			str = (char *)ft_calloc((i + 2), sizeof(char)); 
			if (!str)
				return (NULL);
			while (j <= i)
			{
				str[j] = buf[j];
				j++;
			}
			return (str);
		}
		i++;
	}
	return (buf);
}

int	is_intro(char *buf)
{
	int i;

	if (buf == NULL)
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

char	*after_n(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (buf + 1);
		buf++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*buf;
	char		*str;
	char		*temp;

	str = NULL;
	temp = NULL;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //PROTEGER
	if (!buf)
		return (NULL);
	if (is_intro(extra))
	{
		str = real_buf(extra); //PROTEGER
		if (!str)
			return (NULL);
		extra = after_n(extra);
		return (str);
	}
	if (extra != 0)
	{
		str = ft_strdup(extra); //PROTEGER
		if (!str)
			return (NULL);
	}
	extra = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = 0;
		if (is_intro(buf))
		{
			temp = real_buf(buf); //PROTEGER Y LIBERAR
			if (!temp)
				return (NULL);
			str = ft_strjoin(str, temp); //PROTEGER Y LIBERAR
			if (!str)
			{
				free(temp);
				return (NULL);
			}
			extra = after_n(buf);
			return (str);
		}
		str = ft_strjoin(str, buf); //PROTEGER Y LIBERAR
		if (!str)
			return (NULL);
	}
	return (str);
}

int main (void)
{
	int fd = open("test.txt", O_RDONLY);
	char *a = get_next_line(fd);
	while (a != NULL)
	{
		printf("%s", a);
		a = get_next_line(fd);
	}
	return 0;
}
