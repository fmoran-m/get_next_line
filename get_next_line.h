#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFFER_SIZE 5

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
t_list                  *ft_lstnew(void *content);
void                    ft_lstadd_back(t_list **lst, t_list *new);
void                    ft_lstclear(t_list **lst, void (*del)(void*));
void			*ft_calloc(size_t count, size_t size);
#endif
