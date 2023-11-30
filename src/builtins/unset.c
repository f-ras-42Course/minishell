/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_unset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 14:27:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/28 13:38:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	prepare_unset(t_exe *executor, t_cmd *command)
{
	int		index;

	index = 1;
	while (command->split[index])
	{
		unset(executor, command->split[index]);
		index++;
	}
}

void	unset(t_exe *executor, char *key)
{
	t_envp	*head;
	t_envp	*prev;

	head = executor->envp_list;
	prev = NULL;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			if (prev == NULL)
				executor->envp_list = head->next;
			else
				prev->next = head->next;
			free(head->key);
			free(head->value);
			free(head);
			return ;
		}
		prev = head;
		head = head->next;
	}
}
