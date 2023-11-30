/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 13:38:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 13:53:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*extract_command(char *str)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	output = ft_substr(str, i + 1, ft_strlen(str));
	return (output);
}

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	*command_name;
	char	**split_command;

	command_name = extract_command(command->command_name);
	split_command = ft_split(command_name, ' ');
	export_all_keys(executor, split_command, 0);
	empty_array(split_command);
	free(command_name);
	return ;
}

void	export(t_exe *executor, char *key, char *value)
{
	t_envp	*head;

	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			free(head->value);
			head->value = ft_strdup(value);
			return ;
		}
		head = head->next;
	}
	add_node_envp(&executor->envp_list, key, value);
}
