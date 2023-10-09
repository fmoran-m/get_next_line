/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:30:12 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/09 15:28:09 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	list_t	*node;
	list_t	**lst;
	char	buf[5];
	size_t	r_len;
	int		lst_size;
	char	*str;
	int		i;
	int		j;

	r_len = sizeof(buf);
	lst = NULL;
	while(read(fd, buf, r_len) > 0)
	{
		node = ft_lstnew(buf);
		ft_lstadd_back(lst, node);
	}
	lst_size = ft_lstsize(node) * r_len;
	str = malloc((lstsize + 1) * sizeof(char));
	i = 0;
	while (node)  
	{
		j = 0;
		while (node->content[j])
		{
			str[i] = node->content[j];
			j++;
			i++;
		}
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
	return (0);
}
