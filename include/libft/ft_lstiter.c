/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 11:17:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/01 11:18:08 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node. */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst != 0 && f != 0)
	{
		temp = lst;
		while (temp)
		{
			f(temp -> content);
			temp = temp -> next;
		}
	}
}
