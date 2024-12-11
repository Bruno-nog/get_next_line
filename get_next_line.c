/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:35:48 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/11 13:06:48 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_extract_line(t_gnl_list **lst, char *line, int lenght_line)
{
	t_gnl_list	*temp;
	int			displacer;

	temp = *lst;
	displacer = 0;
	lenght_line += ft_line_size(temp);
	line = (char *)malloc(sizeof(char) * (lenght_line + 1));
	if (!line)
	{
		ft_del(lst);
		return (NULL);
	}
	displacer = ft_copy_to_line(temp, line, displacer);
	line[lenght_line] = '\0';
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
	if (read(fd, &line, BUFFER_SIZE) < 0)
	{
		ft_del(&lst);
		return (NULL);
	}
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
