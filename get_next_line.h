#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif