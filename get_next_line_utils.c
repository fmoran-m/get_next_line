/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:00:13 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/09 19:34:09 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		ptr[i] = s2[k];
		i++;
		k++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strdup(const char *s1)
{
        size_t  len;
        size_t  i;
        char    *ptr;

        len = ft_strlen(s1);
        ptr = (char *) malloc(len * (sizeof(char)) + 1);
        if (ptr == 0)
               return (0);
        i = 0;
        while (s1[i])
        {
                ptr[i] = s1[i];
                i++;
        }
        ptr[i] = '\0';
        return (ptr);
}

void    *ft_calloc(size_t count, size_t size)
{
        char    *ptr;
        size_t  i;
        size_t  total_amount;

        i = 0;
//        if (count == SIZE_MAX || size == SIZE_MAX)
 //               return (0);
        total_amount = size * count;
        ptr = malloc(total_amount);
        if (ptr == 0)
                return (0);
        while (i < total_amount)
        {
                ptr[i] = 0;
                i++;
        }
        return (ptr);
}

char    *ft_strchr(char *s, int c)
{
        unsigned char   ca;

        ca = c;
        while (*s)
        {
	    if (*s == ca)
		return ((char *)s);
            s++;
        }
        if (*s == ca)
	    return ((char *)s + 1);
        return (0);
}
