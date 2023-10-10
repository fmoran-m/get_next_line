/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:30:12 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/09 19:39:27 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*limit_buf(char *buf)
{
    int	    i;
    int	    j;
    char    *ptr;

    i = 0;
    j = 0;
    while (buf[i] != '\n')
	i++;
    ptr = (char *)ft_calloc(sizeof(char), (i + 2));
    if (ptr == NULL)
	return (NULL);
    while (j < i)
    {
	ptr[j] = buf[j];
	j++;
    }
    return (ptr);
}

int buf_bool(char *buf)
{
    int i;

    i = 0;
    while(buf[i])
    {
	if (buf[i] == '\n')
	    return (1);
	i++;
    }
    return (0);
}

char	*get_next_line(int fd)
{
    static char	    *buf;
    char	    *str;
    size_t	    r_len;
    char	    *temp;
    char	    *n_buf;

    if (fd < 0)
	return (NULL);
    str = NULL;
    if (buf != NULL)
	buf = ft_strchr(buf, '\n');
    r_len = sizeof(buf) - 1;
    while (read(fd, buf, r_len) > 0)
    {
	buf[r_len] = 0;
	if (buf_bool(buf) == 0)
	{
	    if (str == NULL)
	    {
		str = ft_strdup(buf);
		if (str == NULL)
		    return (NULL);
	    }
	    else
	    {
		temp = ft_strjoin(str, buf);
		if (temp == NULL)
		{
		    free(str);
		    return (NULL);
		}
		free (str);
		str = temp;
	    }
	}
	else
	{
	    if (str == NULL)
	    {
		str = limit_buf(buf);
		if (str == NULL)
		    return (NULL);
		return (str);
	    }
	    else
	    {
		n_buf = limit_buf(buf);
		temp = ft_strjoin(str, n_buf);
		if (temp == NULL)
		{
		    free(str);
		    return (NULL);
		}
		free(str);
		str = temp;
		return (str);
	    }
	} 
    }
    return (str);
}

int	main(void)
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free (str);
	close(fd);
	return (0);
}
