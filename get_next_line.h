/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:36:08 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/13 16:24:46 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;

char		*get_next_line(int fd);
void		ft_add_end(t_gnl_list **lst, char *buffer);
void		ft_del(t_gnl_list **lst);
void		ft_copy_to_line(t_gnl_list *lst, char *line);
int			ft_line_size(t_gnl_list *temp);
int			ft_found_newline(t_gnl_list *lst);
t_gnl_list	*ft_last_node(t_gnl_list **lst);
char		*ft_extract_line(t_gnl_list **lst);
void		ft_lstnew(t_gnl_list **lst, int fd);
void		ft_lstclear(t_gnl_list **lst);

#endif