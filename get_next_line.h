/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:08:06 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/31 15:33:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
//# define BUFFER_SIZE 10 

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(char *s);
char			*ft_strdup(char *s1);
void			free_file(char **file);
#endif