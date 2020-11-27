/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:57 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/11/27 12:35:58 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	index = -1;
	if (!(res = (char *)malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	while (++index < i)
		res[index] = s1[index];
	index = -1;
	while (++index < j)
		res[index + i] = s2[index];
	res[index + i] = 0;
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = -1;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		res[i] = ((char *)s)[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < (unsigned int)ft_strlen(s) + 1)
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start >= ft_strlen(s))
		return (res);
	while (++i < (int)len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
