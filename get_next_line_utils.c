/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:41:02 by brunogue          #+#    #+#             */
/*   Updated: 2024/11/25 18:23:05 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Procura o nó correspondente ao FD, ou cria um novo se não encontrar.
t_fd_node *get_fd_node(t_fd_node **head, int fd)
{
    t_fd_node *current = *head;

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

void remove_fd_node(t_fd_node **head, int fd)
{
    t_fd_node *current = *head;
    t_fd_node *prev = NULL;

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

char *str_join(char *s1, char *s2)
{
    char *result;
    size_t len1 = 0;
    size_t len2 = 0;

    if (s1)
        while (s1[len1])
            len1++;
    if (s2)
        while (s2[len2])
            len2++;
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    for (size_t i = 0; i < len1; i++)
        result[i] = s1[i];
    for (size_t i = 0; i < len2; i++)
        result[len1 + i] = s2[i];
    result[len1 + len2] = '\0';
    free(s1);
    return (result);
}

// Procura o '\n' na string
int find_newline(const char *str)
{
    int i = 0;

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

// Extrai a linha até o '\n'
char *extract_line(char *remainder)
{
    int i = 0;
    char *line;

    if (!remainder)
        return (NULL);
    while (remainder[i] && remainder[i] != '\n')
        i++;
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    for (int j = 0; j < i; j++)
        line[j] = remainder[j];
    if (remainder[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

char *update_remainder(char *remainder)
{
    int i = 0;
    int j = 0;
    char *new_remainder;

    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder[i]) {
        free(remainder);
        return (NULL);
    }
    new_remainder = malloc(ft_strlen(remainder) - i);
    if (!new_remainder)
        return (NULL);
    i++;
    while (remainder[i])
        new_remainder[j++] = remainder[i++];
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}
