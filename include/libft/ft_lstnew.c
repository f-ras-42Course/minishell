/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:45:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/01 12:26:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates with malloc  and returns a new node. The member variable 
’content’ is initialized with the value of the parameter ’content’. 
The variable ’next’ is initialized to NULL. Returns the new node */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
		node -> content = NULL;
	else
		node -> content = content;
	node -> next = NULL;
	return (node);
}
