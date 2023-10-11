/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:00:13 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/11 19:43:03 by fmoran-m         ###   ########.fr       */
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
/*
t_list  *ft_lstnew(void *content)
{
        t_list  *new;

        new = (t_list *)malloc(sizeof(t_list));
        if (new == NULL)
                return (NULL);
        new -> content = content;
        new -> next = 0;
        return (new);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *temp;

        if (!new)
                return ;
        temp = *lst;
        if (*lst == NULL)
                *lst = new;
        else
        {
	    while(temp->next != 0)
		temp = temp->next;
            temp->next = new;
        }
}

void    ft_lstclear(t_list **lst)
{
        t_list  *temp;

        if (!lst)
                return ;
        while (*lst)
        {
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
        }
        *lst = NULL;
}
*/

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
			return ((char *)s);
		s++;
	}
	if (*s == ca)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2) //SIN CONTROL DE ERRORES PARA PODER PASARLE UN NULL
{
	char	*ptr;
	size_t	i;
	size_t	k;

	if (!s1)
	{
		ptr = ft_strdup(s2);
		return (ptr);
	}
	i = 0;
	k = 0;
	ptr = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
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
	return (ptr);
}

char	*ft_strdup(char *s1) //SIN CONTROL DE ERRORES PARA PASARLE UN NULL
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len * (sizeof(char)) + 1);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
