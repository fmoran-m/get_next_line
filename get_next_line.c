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

char	*real_buffer(char *buf)
{
    int	    i;
    int	    j;
    char    *str;

    i = 0;
    j = 0;
    str = NULL;
    while (buf[i] && buf[i] != '\n')
	i++;
    if (buf[i] == 0)
	return (buf);
    else
    {
	str = (char *)ft_calloc(sizeof(char), (i+2));
	if (!str)
	    return (NULL);
	while (j < i)
	{
	    str[j] = buf[j];
	    j++;
	}
	return (str);
    }
}

char	*get_next_line(int fd)
{
    static char	*buf;
    char	*str;
    char	*temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
    str = NULL;
    if (buf != NULL)
    {
	buf = ft_strchr(buf, '\n'); //Usar temporal, puede que no haya un \n
	if (buf != 0)
	{
	    temp = real_buffer(buf);
	    if(!temp)
		return (NULL);
	    str = ft_strdup(temp);
	    if (str == NULL)
	    {
		free(temp);
		return (NULL);
	    }
	}
    }
    else
    {
	buf = ft_calloc(1, 1);
	if (!buf)
	    return (NULL);
    }
    while (read(fd, buf, BUFFER_SIZE) > 0)
    {
	buf[BUFFER_SIZE] = 0;
	temp = real_buffer(buf);
	if (!temp)
	{
	    free(temp);
	    return (NULL);
	}
	if (!str)
	{
	    str = ft_strdup(temp);
	    if(!str)
		return (NULL);
	}
	else
	{
	    str = ft_strjoin(str, temp);
	    if (!str)
	    {	
		free(str);
		return (NULL);
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
//	str = get_next_line(fd);
//	printf("%s\n", str);
//	free (str);
	close(fd);
	return (0);
}
