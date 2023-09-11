/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:27:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/01 11:16:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes as a parameter a node and frees the memory of the node’s content 
using the function ’del’ given as a parameter and frees the node. */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != 0 && del != 0)
	{
		del(lst -> content);
		free(lst);
	}
}
