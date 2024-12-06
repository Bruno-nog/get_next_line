/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:36:08 by brunogue          #+#    #+#             */
/*   Updated: 2024/12/06 17:52:20 by brunogue         ###   ########.fr       */
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

typedef struct s_gnl_list
{
    char	*content;
	struct s_gnl_list	*next;
}	t_gnl_list;



#endif