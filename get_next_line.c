/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:41:04 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/25 18:16:55 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static t_fd_node *head = NULL;
    t_fd_node *node;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    node = get_fd_node(&head, fd);
    if (!node)
        return (NULL);
    while (!find_newline(node->remainder))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        node->remainder = str_join(node->remainder, buffer);
    }
    if (!node->remainder || *node->remainder == '\0')
    {
        remove_fd_node(&head, fd);
        return (NULL);
    }
    line = extract_line(node->remainder);
    node->remainder = update_remainder(node->remainder);
    return (line);
}
// int main(void)
// {
// 	get_next_line(0);
// 	return (0);
// }