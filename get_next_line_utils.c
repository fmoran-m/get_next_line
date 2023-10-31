/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:39:08 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/31 15:39:25 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;
	size_t		total_amount;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	total_amount = size * count;
	ptr = malloc(total_amount);
	if (!ptr)
		return (NULL);
	while (i < total_amount)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	free_file(char **file)
{
	if (*file)
	{
		free (*file);
		*file = NULL;
	}
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	ptr = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!ptr)
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
	ptr = (char *)malloc(len * (sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
