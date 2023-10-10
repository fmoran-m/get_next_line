#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFFER_SIZE 5

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(char *s, int c);
#endif
