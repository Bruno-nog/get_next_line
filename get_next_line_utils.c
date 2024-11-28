/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:41:02 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/28 16:15:59 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_node	*get_fd_node(t_fd_node **head, int fd)
{
    t_fd_node	*current;

    if (!head)
        return (NULL);
    current = *head;
    while (current)
    {
        if (current->fd == fd)
            return (current);
        current = current->next;
    }
    current = malloc(sizeof(t_fd_node));
    if (!current)
        return (NULL);
    current->fd = fd;
    current->remainder = NULL;
    current->next = *head;
    *head = current;
    return (current);
}


void	remove_fd_node(t_fd_node **head, int fd)
{
    t_fd_node	*current;
    t_fd_node	*prev;

    current = *head;
    prev = NULL;
    while (current)
    {
        if (current->fd == fd)
        {
            if (prev)
                prev->next = current->next;
            else
                *head = current->next;
            if (current->remainder)
                free(current->remainder);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
int	find_newline(const char *str)
{
    int	i;

    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*extract_line(char *remainder)
{
    int		i;
    char	*line;
    int		j;

    i = 0;
    j = 0;
    if (!remainder)
        return (NULL);
    while (remainder[i] && remainder[i] != '\n')
        i++;
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    while (j < i)
	{
        line[j] = remainder[j];
		j++;
	}
    if (remainder[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char	*update_remainder(char *remainder)
{
    int		i;
    int		j;
    char	*new_remainder;

    i = 0;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder[i])
    {
        free(remainder);
        return (NULL);
    }
    new_remainder = malloc(ft_strlen(remainder) - i);
    if (!new_remainder)
        return (NULL);
    i++;
    j = 0;
    while (remainder[i])
        new_remainder[j++] = remainder[i++];
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    if (!s1 && !s2)
        return (NULL);
    str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    if (s1)
    {
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        free(s1);
    }
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}




















// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	size_t			length;
// 	void			*buffer;
// 	unsigned char	*ptr;
// 	size_t			i;

// 	if ((nmemb != 0 && size) > ((size_t)-1) / nmemb)
// 		return (NULL);
// 	length = size * nmemb;
// 	buffer = malloc(length);
// 	if (!buffer)
// 		return (NULL);
// 	ptr = (unsigned char *)buffer;
// 	i = 0;
// 	while (i < length)
// 		ptr[i++] = 0;
// 	return (buffer);
// }
// // Procura o nó correspondente ao FD, ou cria um novo se não encontrar.
// t_fd_node *get_fd_node(t_fd_node **head, int fd)
// {
//     t_fd_node *current = *head;
// 	char *read_buffer;

// 	if (!head)
// 		head = ft_calloc(1, sizeof(char));
// 	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//     while (current)
//     {
//         if (current->fd == fd)
//             return (current);
//         current = current->next;
//     }
//     current = malloc(sizeof(t_fd_node));
//     if (!current)
//         return (NULL);
//     current->fd = fd;
//     current->remainder = NULL;
//     current->next = *head;
//     *head = current;
//     return (current);
// }

// void remove_fd_node(t_fd_node **head, int fd)
// {
//     t_fd_node *current = *head;
//     t_fd_node *prev = NULL;

//     while (current)
//     {
//         if (current->fd == fd)
//         {
//             if (prev)
//                 prev->next = current->next;
//             else
//                 *head = current->next;
//             if (current->remainder)
//                 free(current->remainder);
//             free(current);
//             return;
//         }
//         prev = current;
//         current = current->next;
//     }
// }

// int ft_strlen(const char *str)
// {
//     int len = 0;
//     while (str[len])
//         len++;
//     return (len);
// }

// char *ft_strjoin(char *s1, char *s2)
// {
//     char *str;
//     size_t i, j;

//     if (!s1 && !s2)
//         return (NULL);
//     str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
//     if (!str)
//         return (NULL);
//     i = 0;
//     if (s1) {
//         while (s1[i]) {
//             str[i] = s1[i];
//             i++;
//         }
//         free(s1); // Libera a string original
//     }
//     j = 0;
//     while (s2[j])
//         str[i++] = s2[j++];
//     str[i] = '\0';
//     return (str);
// }

// // Procura o '\n' na string
// int find_newline(const char *str)
// {
//     int i = 0;

//     if (!str)
//         return (-1);
//     while (str[i])
//     {
//         if (str[i] == '\n')
//             return (i);
//         i++;
//     }
//     return (-1);
// }

// // Extrai a linha até o '\n'
// char *extract_line(char *remainder)
// {
//     int i;
//     char *line;
//     int j;
    
//     j = 0;
//     i = 0;
//     if (!remainder)
//         return (NULL);
//     while (remainder[i] && remainder[i] != '\n')
//         i++;
//     line = malloc(i + 2);
//     if (!line)
//         return (NULL);
//     while (j < i)
//     {
//         line[j] = remainder[j];
//         j++;
//     }
//     if (remainder[i] == '\n')
//         line[i++] = '\n';
//     line[i] = '\0';
//     return (line);
// }

// char *update_remainder(char *remainder)
// {
//     int i = 0, j = 0;
//     char *new_remainder;

//     while (remainder[i] && remainder[i] != '\n')
//         i++;
//     if (!remainder[i]) {
//         free(remainder);
//         return (NULL);
//     }
//     new_remainder = malloc(ft_strlen(remainder) - i);
//     if (!new_remainder)
//         return (NULL);
//     i++;
//     while (remainder[i])
//         new_remainder[j++] = remainder[i++];
//     new_remainder[j] = '\0';
//     free(remainder);
//     return (new_remainder);
// }
