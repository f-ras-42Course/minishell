/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redir_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 15:12:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 00:39:23 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_file	*last_node(t_file *filename)
{
	t_file	*temp;

	temp = filename;
	if (filename != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_file	*new_redir(char *name, int mode)
{
	t_file	*node;

	node = malloc(sizeof(t_file));
	if (node == NULL)
		return (NULL);
	node->mode = mode;
	node->delimiter = NULL;
	node->filename = NULL;
	if (node->mode == HEREDOC)
	{
		node->delimiter = ft_strdup(name);
		node->filename = ft_strdup("build/.heredoc");
	}
	else
	{
		if (name != NULL)
			node->filename = ft_strdup(name);
	}
	node->next = NULL;
	return (node);
}

void	add_redir(t_file **redirections, char *name, int mode)
{
	t_file	*last;
	t_file	*new;

	new = new_redir(name, mode);
	if (*redirections != NULL && new != NULL)
	{
		last = last_node(*redirections);
		last->next = new;
	}
	else
		*redirections = new;
}
