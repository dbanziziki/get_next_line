/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:26:59 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/09 11:09:18 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# define MAX_FD 4096

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	ft_substr(char const *s, unsigned int start, size_t len);

#endif
