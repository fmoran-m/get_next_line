#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
char			*get_next_line(int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
#endif
