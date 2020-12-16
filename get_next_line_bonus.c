/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:40 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/15 23:08:16 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save_buffer(char **file, char *buffer, int ret)
{
	char	*temp_content;

	buffer[ret] = '\0';
	if (*file == NULL)
		temp_content = ft_strndup(buffer, ret);
	else
	{
		temp_content = ft_strjoin(*file, buffer);
		free(*file);
	}
	*file = temp_content;
	if (ft_strchr(*file, '\n'))
		return (1);
	return (0);
}

static int	extract_line(char **src, char **line)
{
	char	*temp1;
	size_t	len;

	len = 0;
	while ((*src)[len] && (*src)[len] != '\n')
		len++;
	if ((*src)[len] == '\n')
	{
		*line = ft_strndup(*src, len);
		temp1 = ft_strndup(*src + (len + 1), ft_strlen(*src + (len + 1)));
		free(*src);
		*src = temp1;
	}
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
	static char	*file[OPEX_MAX];
	int			ret;

	if ((fd < 0 || line == NULL || fd >= OPEX_MAX || BUFFER_SIZE <= 0))
		return (-1);
	if (ft_strchr(file[fd], '\n'))
		return (extract_line(&file[fd], line));
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		if (save_buffer(&file[fd], buffer, ret) || ret == 0)
			break ;
	}
	free(buffer);
	return (ret < 0 ? -1 : extract_line(&file[fd], line));
}
