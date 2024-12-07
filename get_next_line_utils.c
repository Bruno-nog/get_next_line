/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:40:29 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/07 18:32:21 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_last_node(t_gnl_list **lst)
{
	t_gnl_list	*temp;
	
	temp = *lst;
	if (temp == NULL)
		return (temp);
	while (temp -> next != NULL)
		temp = temp -> next;
	return (temp);
}

int	found_newline(t_gnl_list *lst)
{
	int	i;
	
	if (lst)
		return (0);
	while (lst)
	{
		i = 0;
		while  (lst -> content[i] && i < BUFFER_SIZE)
		{
			if (lst -> content[i] == '\n' || lst -> content[i] == '\0')
				return (1);
			++i;	
		}
		lst = lst -> next;
	}
	return (0);
}

int	ft_cont_size(t_gnl_list *temp)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	while (temp)
	{
		i = 0;
		while (temp -> content[i])
		{
			if (temp -> content[i] == '\n')
				return (++x);
			++i;
			++x;
		}
		temp = temp -> next;
	}
	return (x);
}

int	ft_cpylst(t_gnl_list *temp, char *line, int displacer)
{
	int	i;

	i = 0;
	while (temp)
	{
		while (temp -> content[i] != '\0')
		{
			if (temp -> content[i] == '\n')
				return (line[displacer++] = temp -> content[i]);
			else
				line[displacer++] = temp -> content[i++];
		}
		temp = temp -> next;
	}
	return (dispĺacer);
}

void	ft_del(t_gnl_list **lst)
{
	t_gnl_list *temp;
	
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