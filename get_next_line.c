/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:40 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/03 18:58:30 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_strfree(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static int		extract_line(char **src, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*src)[len] != '\n' && (*src)[len] != '\0')
		len++;
	if ((*src)[len] == '\n')
	{
		*line = ft_substr(*src, 0, len);
		temp = ft_strdup(&((*src)[len + 1]));
		free(*src);
		*src = temp;
		if ((*src)[0] == '\0')
			ft_strfree(src);
	}
	else
	{
		*line = ft_strdup(*src);
		ft_strfree(src);
		return (0);
	}
	return (1);
}

int				return_value(char **file, char **line, int fd, int ret)
{
	if (ret == 0 && file[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return ((ret < 0) ? -1 : extract_line(&file[fd], line));
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*file[MAX_FD];
	char			*temp_content;
	int				ret;

	if ((fd < 0 || line == NULL))
		return (-1);
	if (ft_strchr(file[fd], '\n'))
		return (extract_line(&file[fd], line));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strdup(buffer);
		else
		{
			temp_content = ft_strjoin(file[fd], buffer);
			free(file[fd]);
			file[fd] = temp_content;
		}
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	return (return_value(file, line, fd, ret));
}

//jaeskim 
//JaeSeoKim
