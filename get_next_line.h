#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H 
# ifndef	BUFFER_SIZE
//#  define	BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s1);
#endif
