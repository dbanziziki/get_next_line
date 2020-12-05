/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanzizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:35:40 by dbanzizi          #+#    #+#             */
/*   Updated: 2020/12/05 12:25:31 by dbanzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list		*get_correct_file(t_list **list, int fd)
{
	t_list	*temp;
	t_list	*new;

	temp = *list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
	new->next = *list;
	new->fd = fd;
	new->content = NULL;
	*list = new;
	return (new);
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
	}
	else
	{
		*line = *src;
		*src = 0;
		return (0);
	}
	return (1);
}

int				return_value(char *file, char **line, int ret)
{
	if (ret == 0 && file == NULL)
	{
		return (0);
	}
	else
		return ((ret < 0) ? -1 : extract_line(&file, line));
}

int				get_next_line(int fd, char **line)
{
	char			*buffer;
	static t_list		*file;
	char			*temp_content;
	int				ret;

	if (fd < 0 || line == NULL || !(buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	file = get_correct_file(&file, fd);
	if (ft_strchr(file->content, '\n'))
		return (extract_line(&file->content, line));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (file->content == NULL)
			file->content = ft_strdup(buffer);
		else
		{
			temp_content = ft_strjoin(file->content, buffer);
			free(file->content);
			file->content = temp_content;
		}
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	free(buffer);
	return (return_value(file->content, line, ret));
}

//jaeskim 
//JaeSeoKim
