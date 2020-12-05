/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:46 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/05 11:41:52 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 42 

#endif

# define MAX_FD 4096

typedef struct		s_list
{
	char 		*content;
	char		*next_line;
	int		fd;
	struct s_list	*next;
}			t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
