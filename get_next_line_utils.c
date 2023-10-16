/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:00:13 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/12 21:44:38 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size)
{
        char    *ptr;
        size_t  i;
        size_t  total_amount;

        i = 0;
        if (count == SIZE_MAX || size == SIZE_MAX)
              return (0);
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

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	ca;

	ca = c;
	while (*s)
	{
		if (*s == ca)
			return ((char *)s + 1);
		s++;
	}
	if (*s == ca)
		return ((char *)s + 1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	if (!s1)
	{
	    ptr = ft_strdup(s2);
	    return (ptr);
	}
	if (!s2)
	    return (NULL);
	i = 0;
	k = 0;
	ptr = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (ptr == NULL)
	    return (NULL);
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
	free (s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!s1)
	    return (NULL);
	len = ft_strlen(s1);
	ptr = (char *)malloc(len * (sizeof(char)) + 1); i = 0;
	while (s1[i])
	{
	    ptr[i] = s1[i];
	    i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
