/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_struct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 15:02:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 12:18:09 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*last_command(t_cmd *command)
{
	t_cmd	*temp;

	temp = command;
	if (command != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_cmd	*init_command(int index)
{
	t_cmd	*node;

	node = ft_malloc(sizeof(t_cmd));
	node->command_name = ft_strdup("");
	node->outputs = NULL;
	node->inputs = NULL;
	node->output_redirection = false;
	node->input_redirection = false;
	node->split = NULL;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	add_command(t_cmd **commands, int index)
{
	t_cmd	*last;
	t_cmd	*new;

	new = init_command(index);
	if (*commands != NULL && new != NULL)
	{
		last = last_command(*commands);
		last->next = new;
	}
	else
		*commands = new;
}
