/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:50 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/13 00:23:23 by fmoran-m         ###   ########.fr       */
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

char	*check_static(char *str, char *extra)
{
	if (is_intro(extra))
	{
		str = real_buf(extra);
		extra = ft_strchr(extra, '\n');
		return (str);
	}
	if (extra != 0)
		str = ft_strdup(extra);
	return (str);
}

char	*check_loop(char *str, char *buf)  
{
	char	*temp;

	temp = NULL;
	if (is_intro(buf))
	{
		temp = real_buf(buf);
		str = ft_strjoin(str, temp);
		free (temp);
		return (str);
	}
	str = ft_strjoin(str, buf);
	return (str);
}
		
char	*get_next_line(int fd)
{
	static char	*extra;
	char		*buf;
	char		*str;
	char		*temp;

	str = NULL;
	temp = NULL;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	str = check_static(str, extra);
	if(is_intro(extra))
	{
		extra = ft_strchr(extra, '\n');
		return (str);
	}
	extra = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		str = check_loop(str, buf);
		if (is_intro(buf))
		{
			extra = ft_strchr(buf, '\n'); 
			return (str);
		}
	}
	free (buf);
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
