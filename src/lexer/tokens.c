/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 13:21:42 by fras          #+#    #+#                 */
/*   Updated: 2023/11/24 08:36:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*create_token(char *value)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->type = NONE;
	new->value = value;
	new->next = NULL;
	return (new);
}

t_tokens	*add_new_token(char *value, t_tokens **prev)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->type = NONE;
	new->value = value;
	new->next = NULL;
	(*prev)->next = new;
	return (new);
}

void	clear_tokens(t_tokens **node)
{
	t_tokens	*prevnode;

	if (!*node)
		return ;
	prevnode = *node;
	free((*node)->value);
	while ((*node)->next)
	{
		*node = (*node)->next;
		free((*node)->value);
		free(prevnode);
		prevnode = *node;
	}
	free(*node);
	*node = NULL;
}
