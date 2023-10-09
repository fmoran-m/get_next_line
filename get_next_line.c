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

char	*get_next_line(int fd)
{
	t_list		*node;
	t_list		*lst;
	static char	buf[5];
	size_t		r_len;
	char		*str;
	int			i;
	int			j;

	r_len = sizeof(buf) - 1;
	lst = NULL;
	while (read(fd, buf, r_len) > 0)
	{
		buf[r_len] = 0;
		node = ft_lstnew(buf);
		if (!lst)
			lst = node;
		else
			ft_lstadd_back(&lst, node);
	}
	str = (char *)malloc(sizeof(buf) * ft_lstsize(lst) + 1);
	i = 0;
	node = lst;
	while (node)
	{
		j = 0;
		while (((char *)node->content)[j])
		{
			str[i] = ((char *)node->content)[j];
			i++;
			j++;
		}
		node = node->next;
	}
	str[i] = 0;
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
	return (0);
}
