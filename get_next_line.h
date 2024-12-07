/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:36:08 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/07 16:26:44 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 123
# endif

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>

typedef struct s_gnl_list
{
    char	*content;
	struct s_gnl_list	*next;
}	t_gnl_list;

char	*get_next_line(int fd);
void	ft_lstnew(t_gnl_list **lst, int fd);
void	ft_add_end(t_gnl_list **lst, char *buffer);


#endif