/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:35:48 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/06 18:20:37 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstnew(t_gnl_list **lst, int fd)
{
	int		char_read;
	char	*buffer;
	
	char_read = 0;
	while (!found_newline(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (ft_del(lst));
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst;
	char	*line;
	int		lenght_line;
	
	line = NULL;
	lenght_line = 0;
	if(read(fd, &line, 0) < 0)
	{
		ft_del(&lst);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_lstnew(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line = ft_new_line(&lst, line, lenght_line);
	if (lst == NULL)
		return (NULL);
	ft_lstclear(&lst);
	return (line);
}


/*
int	main(void)
{
	int		fd;
	char	*rslt;

	fd = open("file.txt", O_RDONLY);
	rslt = get_next_line(fd);
	printf("line -> %s", rslt);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*putito;

	fd = open("test.txt", O_RDONLY);
	putito = get_next_line(fd);
	while (putito)
	{
		printf("%s", putito);
		free(putito);
		putito = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
