/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:40:59 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/25 18:07:15 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_fd_node
{
	int					fd;
    char				*remainder;
	struct s_fd_node	*next;
}	t_fd_node;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif


char *get_next_line(int fd);
t_fd_node *get_fd_node(t_fd_node **head, int fd);
void remove_fd_node(t_fd_node **head, int fd);
int ft_strlen(const char *str);
char *str_join(char *s1, char *s2);
int find_newline(const char *str);
char *extract_line(char *remainder);
char *update_remainder(char *remainder);

#endif