#include "get_next_line.h"
#include <stdio.h>

static int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	if (!s1)
		return (-1);
	//printf("%s\n", (char*)s1);
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = -1;
	while (++i < n && *(s1_ptr + i) == *(s2_ptr + i))
		;
	if (i == n)
		return (0);
	return (*(s1_ptr + i) - *(s2_ptr + i));
}

static int	extract_line(char **src, char **line)
{
	int	len;
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
	}
	//printf("{--%s--}\n", *src);
	return (1);
}

static t_lst	*get_correct_file(t_lst **lst, int fd)
{
	t_lst	*current_fd;	

	current_fd = *lst;
	while (current_fd)
	{
		if (current_fd->fd == fd)
			return (current_fd);
		current_fd = current_fd->next;
	}
	if (!(current_fd = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
	current_fd->content = "\0";	
	current_fd->fd = fd;
	current_fd->next = *lst;
	*lst = current_fd;
	return (*lst);
}

int		get_next_line(int fd, char **line)
{
	char		res[BUFF_SIZE + 1];
	static t_lst	*file;
	char		*temp_content;
	int		ret;

	if ((fd < 0 || line == NULL))
		return (-1);
	file = get_correct_file(&file, fd);
	while ((ret = read(fd, res, BUFF_SIZE)) > 0)
	{	
		res[ret] = '\0';
		if (!ft_memcmp(file->content, "\0", 1) || !(file)->content)
			file->content = ft_strdup(res);
		else
		{
			temp_content = ft_strjoin(file->content, res);
			free(file->content);
			file->content = temp_content;
		}
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && file->content == NULL)
		return (0);
	else
		return (extract_line(&(file->content), line));
}
