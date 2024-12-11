/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:35:48 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/11 19:08:59 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"





/*
void	ft_add_end(t_gnl_list **lst, char *buf)
{
	t_gnl_list	*new_node;
	t_gnl_list	*last_node;

	if (!buf[0])
		return (free(buf));
	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
	{
		free(buf);
		return (ft_del(lst));
	}
	last_node = ft_last_node(lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	ft_lstclear(t_gnl_list **lst)
{
	t_gnl_list	*last_node;
	int			i;
	int			k;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_del(lst));
	last_node = ft_last_node(lst);
	i = 0;
	k = 0;
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] != '\0' && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	ft_del(lst);
	ft_add_end(lst, buf);
}

char	*ft_extract_line(t_gnl_list **lst, char *line, int l_line)
{
	t_gnl_list	*temp;
	int			displacer;

	temp = *lst;
	displacer = 0;
	l_line += ft_line_size(temp);
	line = (char *)malloc(sizeof(char) * (l_line + 1));
	if (!line)
	{
		ft_del(lst);
		return (NULL);
	}
	displacer = ft_copy_to_line(temp, line, displacer);
	line[l_line] = '\0';
	return (line);
}

void	ft_lstnew(t_gnl_list **lst, int fd)
{
	int		char_read;
	char	*temp_buf;

	char_read = 0;
	while (!ft_found_newline(*lst))
	{
		temp_buf = malloc(BUFFER_SIZE + 1);
		if (temp_buf == NULL)
			return (ft_del(lst));
		char_read = read(fd, temp_buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(temp_buf);
			return ;
		}
		temp_buf[char_read] = '\0';
		ft_add_end(lst, temp_buf);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst = NULL;
	char				*line;
	int					lenght_line;

	line = NULL;
	lenght_line = 0;
	// if (read(fd, &line, 0) < 0)
	// {
	// 	ft_del(&lst);
	// 	return (NULL);
	// }
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_lstnew(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line = ft_extract_line(&lst, line, lenght_line);
	if (lst == NULL)
		return (NULL);
	ft_lstclear(&lst);
	return (line);
}

*/




























































/*
void	ft_add_end(t_gnl_list **lst, char *buffer)
{
	t_gnl_list	*last_node;
	t_gnl_list	*new_node;

	if (buffer == NULL)
		return (free(buffer));
	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
	{
		free(buffer);
		return (ft_del(lst));
	}
	last_node = ft_last_node(lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

char	*ft_extract_line(t_gnl_list **lst)
{
	t_gnl_list	*temp;
	char		*line;
	int			lenght_line;
	
	temp = *lst;
	lenght_line = ft_line_size(temp);
	line = (char *)malloc(sizeof(char) * (lenght_line + 1));
	if (!line)
	{
		ft_del(lst);
		return (NULL);
	}
	line = ft_copy_to_line(temp, line);
	return (line);
}

void	ft_lstnew(t_gnl_list **lst, int fd)
{
	int		char_read;
	char	*temp_buf;

	char_read = 0;
	while (!ft_found_newline(*lst))
	{
		temp_buf = malloc(BUFFER_SIZE + 1);
		if (temp_buf == NULL)	
			return (ft_del(lst));
		char_read = read(fd, temp_buf, BUFFER_SIZE);
		if (!char_read || char_read < 0)
		{
			free(temp_buf);
			return ;
		}
		temp_buf[char_read] = '\0';
		ft_add_end(lst, temp_buf);
	}
}

void	ft_lstclear(t_gnl_list **lst)
{
	t_gnl_list	*last_node;
	int			i;
	int			x;
	char		*buffer;

	i = 0;
	x = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_del(lst));
	last_node = ft_last_node(lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		++i;
	while (last_node -> content[i] != '\0' && last_node-> content[i++])
		buffer[x++] = last_node->content[i];
	buffer[x] = '\0';
	ft_del(lst);
	ft_add_end(lst, buffer);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst[1024];
	char				*line;

	line = NULL;
	// if (read(fd, &line, 0) < 0)
	// {
	// 	ft_del(&lst[fd]);
	// 	return (NULL);
	// }
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_lstnew(&lst[fd], fd);	
	if (lst[fd] == NULL)
		return (NULL);
	line = ft_extract_line(&lst[fd]);
	// if (lst[fd] == NULL || line == NULL)
	// {
	// 	free(line);
	// 	free(*lst);
	// 	return (NULL);
	// }
	if (lst[fd] == NULL)
		return (NULL);
	ft_lstclear(&lst[fd]);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	static t_gnl_list	*lst;
// 	char				*line;
// 	int					lenght_line;
// 	char				*temp_lst[1024];

// 	temp_lst = &lst;
// 	line = NULL;
// 	lenght_line = 0;
// 	if (read(fd, &line, 0) < 0)
// 	{
// 		ft_del(&temp_lst[fd][0]);
// 		return (NULL);
// 	}
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	ft_lstnew(&temp_lst[fd][0], fd);
// 	if (&temp_lst[fd][0] == NULL)
// 		return (NULL);
// 	line = ft_extract_line(&temp_lst[fd][0], line, lenght_line);
// 	if (&temp_lst[fd][0] == NULL)
// 		return (NULL);
// 	ft_lstclear(&temp_lst[fd][0]);
// 	return (line);
// }



// int	main(void)
// {
// 	int		fd1, fd2;
// 	char	*putito1, *putito2;
	
// 	fd1 = open("get_next_line.c", O_RDONLY);
// 	fd2 = open("get_next_line.h", O_RDONLY);
// 	putito1 = get_next_line(fd1);
// 	putito2 = get_next_line(fd2);
// 	while ((putito1 != NULL && putito2 != NULL))
// 	{
// 		printf("1: %s", putito1);
// 		printf("2: %s", putito2);
// 		free(putito1);
// 		free(putito2);
// 		putito1 = get_next_line(fd1);
// 		putito2 = get_next_line(fd2);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }

*/