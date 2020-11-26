#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 1
# define MAX_FD 4096

typedef struct		s_lst
{
	char		*content;
	int		fd;
	struct s_lst	*next;
}			t_lst;

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strfree(char **str);

#endif
