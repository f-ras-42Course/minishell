/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:39:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/01 11:31:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node. Creates a new list resulting of the successive applications 
of the function ’f’. The ’del’ function is used to delete the content 
of a node if needed. Returns the new list. NULL if the allocation fails. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*output;

	if (!lst || !f || !del)
		return (NULL);
	output = 0;
	while (lst)
	{
		new = f(lst->content);
		new = ft_lstnew(new);
		if (new == NULL)
		{
			del(new -> content);
			ft_lstclear(&output, del);
			return (NULL);
		}
		ft_lstadd_back(&output, new);
		lst = lst -> next;
	}
	return (output);
}
