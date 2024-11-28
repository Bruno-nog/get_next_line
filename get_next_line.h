/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:40:59 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/28 17:11:16 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>



typedef struct c_list
{
	char			*str;
	struct c_list	*next;
}					t_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif

char	*get_next_line(int fd);
int	get_line_length(t_list *cursor);
char	*separate_line(t_list *cursor);
void	update_next_line(t_list **ptr);
int	ft_find_newline(t_list *next_line);
void	read_and_check_newline(int fd, t_list **ptr_next_line,
		char **ptr_buffer, int bytes_read);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *str);
void	*ft_calloc(size_t nmemb, size_t size);




// typedef struct s_fd_node
// {
// 	int					fd;
//     char				*remainder;
// 	struct s_fd_node	*next;
// }	t_fd_node;

//MEU
// char *get_next_line(int fd);
// t_fd_node *get_fd_node(t_fd_node **head, int fd);
// void remove_fd_node(t_fd_node **head, int fd);
// int ft_strlen(const char *str);
// char *ft_strjoin(char *s1, char *s2);
// int find_newline(const char *str);
// char *extract_line(char *remainder);
// char *update_remainder(char *remainder);
// void	*ft_calloc(size_t nmemb, size_t size);

#endif