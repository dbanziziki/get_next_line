/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <dbanzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:40 by dbanzizi          #+#    #+#             */
/*   Updated: 2021/03/24 15:27:26 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save_buffer(char **file, char *buffer, int ret)
{
	char	*temp_content;

	buffer[ret] = '\0';
	temp_content = 0;
	if (*file == NULL)
	{
		if (!(temp_content = ft_strndup(buffer, ret)))
			return (-1);
	}
	else
	{
		if (!(temp_content = ft_strjoin(*file, buffer)))
			return (-1);
		free(*file);
	}
	*file = temp_content;
	if (ft_strchr(*file, '\n'))
		return (1);
	return (0);
}

static int	ft_cpy_line(char **src, char **line, int len)
{
	char	*temp1;

	if (!src || !(*src))
		return (0);
	if (!(*line = ft_strndup(*src, len)))
		return (-1);
	if (!(temp1 = ft_strndup(*src + (len + 1), ft_strlen(*src + (len + 1)))))
		return (-1);
	free(*src);
	*src = temp1;
	return (1);
}

static int	extract_line(char **src, char **line)
{
	size_t	len;

	len = 0;
	if (!src || !(*src))
		return (0);
	while ((*src)[len] && (*src)[len] != '\n')
		len++;
	if ((*src)[len] == '\n')
		return (ft_cpy_line(src, line, len));
	else
	{
		*line = *src;
		*src = 0;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*file;
	int			ret;

	if ((fd < 0 || line == NULL || fd >= OPEX_MAX || BUFFER_SIZE <= 0))
		return (-1);
	if (ft_strchr(file, '\n'))
		return (extract_line(&file, line));
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		if (save_buffer(&file, buffer, ret) || ret == 0)
			break ;
	}
	free(buffer);
	if (ret < 0)
		return (-1);
	return (extract_line(&file, line));
}
