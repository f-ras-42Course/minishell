/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 13:38:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 01:06:45 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*extract_command(char *str)
{
	char	*output;
	int		i;

	i = 0;
	output = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != ' ')
		i++;
	output = ft_substr(str, i + 1, ft_strlen(str));
	if (!output)
		return (NULL);
	return (output);
}

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	*name;
	char	**split_command;

	name = extract_command(command->command_name);
	if (!ft_strnstr(name, "=", ft_strlen(name)))
	{
		if (is_valid_key(name))
			return ;
		else
		{
			cmd_error("export", ": not a valid identifier\n");
			executor->exit_code = 1;
			return ;
		}
	}
	split_command = ft_split(name, ' ');
	export_all_keys(executor, split_command, NULL, 0);
	empty_array(split_command);
	free(name);
	return ;
}

void	export(t_exe *executor, char *key, char *value)
{
	t_envp	*head;

	if (ft_isdigit(key[0]))
	{
		cmd_error("export", ": not a valid identifier\n");
		executor->exit_code = 1;
		return ;
	}
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
