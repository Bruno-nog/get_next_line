/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:40:29 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/11 19:12:43 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


// int	ft_copy_to_line(t_gnl_list *temp, char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (temp)
// 	{
// 		while (temp->content[i] != '\0')
// 		{
// 			if (temp->content[i] == '\n')
// 				return (line[displacer++] = temp->content[i]);
// 			else
// 				line[displacer++] = temp->content[i++];
// 		}
// 		temp = temp->next;
// 	}
// 	return (displacer);
// }

char	*ft_copy_to_line(t_gnl_list *temp, char *line)
{
	int	i;
	int	k;

	k = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				line[k] = '\n';
				line[++k] = '\0';
				return (line);
			}
			line[k] = temp->content[i];
			++k;
			++i;
		}
		temp = temp->next;
	}
	line[k] = '\0';
	return (line);
}
// char	*ft_copy_to_line(t_gnl_list *temp, char *line)
// {
// 	int	i;
// 	int	k;

// 	k = 0;
// 	while (temp)
// 	{
// 		i = 0;
// 		while (temp->content[i] != '\0' && temp->content[i] != '\n')
// 			line[k++] = temp->content[i++];
// 		temp = temp->next;
// 	}
// 	line[++k] = '\n';
// 	line[++k] = '\0';
// 	return (line);
// }

void	ft_del(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
