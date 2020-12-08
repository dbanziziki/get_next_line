/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:40 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/08 18:22:13 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		extract_line(char **src, char **line)
{
	char	*temp;
	char	*temp1;

	if ((temp = ft_strchr(*src, '\n')))
	{
		*line = ft_strndup(*src, temp - *src);
		temp1 = ft_strndup(temp + 1, ft_strlen(temp + 1));
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

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*file[MAX_FD];
	char			*temp_content;
	int				ret;

	if ((fd < 0 || line == NULL || fd >= MAX_FD || BUFFER_SIZE <= 0))
		return (-1);
	if (ft_strchr(file[fd], '\n'))
		return (extract_line(&file[fd], line));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		buffer[ret] = '\0';
		if (file[fd] == NULL)
			temp_content = ft_strndup(buffer, ret);
		else
		{
			temp_content = ft_strjoin(file[fd], buffer);
			free(file[fd]);
		}
		file[fd] = temp_content;
		if (ft_strchr(file[fd], '\n') || ret == 0)
			break ;
	}
	return (ret < 0 ? -1 : extract_line(&file[fd], line));
}
