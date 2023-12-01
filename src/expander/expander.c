/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:47:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 14:21:57 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expanded_variable(t_exe *executor, char *str, int index)
{
	char	*temp;
	char	*key;
	char	*variable;
	char	*remainder;

	if (index > 1)
		temp = ft_substr(str, 0, index - 1);
	else
		temp = ft_strdup("");
	key = find_variable_name(str, index);
	remainder = ft_substr(str, index + ft_strlen(key), ft_strlen(str));
	variable = get_variable(executor, key);
	printf("%p\n", variable);
	if (!variable)
		variable = ft_strdup("");
	printf("%p\n", variable);
	str = join_expanded_str(temp, variable, remainder);
	printf("%p\n", variable);
	free(temp);
	free(variable);
	free(key);
	free(remainder);
	return (str);
}

char	*expand_string(t_exe *executor, char *str)
{
	char	*temp_output;
	char	*output;
	int		index;

	output = ft_strdup(str);
	index = needs_expansion_heredoc(output, 0, 0);
	while (index != 0)
	{
		temp_output = expanded_variable(executor, output, index);
		free(output);
		output = temp_output;
		index = needs_expansion_heredoc(output, 0, 0);
	}
	return (output);
}

void	expand_command(t_exe *executor, t_cmd *command)
{
	char	*temp_output;
	char	*output;
	char	*input;
	int		index;

	input = command->command_name;
	output = ft_strdup(input);
	index = needs_expansion(output, 0, 0);
	while (index != 0)
	{
		temp_output = expanded_variable(executor, output, index);
		free(output);
		output = temp_output;
		index = needs_expansion(output, 0, 0);
	}
	temp_output = output;
	output = handle_quotes(temp_output, NULL, 0, 0);
	free(command->command_name);
	command->command_name = output;
	free(temp_output);
}

void	run_expander(t_exe *executor)
{
	t_cmd	*head;
	char	**cmd_split;

	head = executor->commands_list;
	while (head != NULL)
	{
		expand_command(executor, head);
		cmd_split = ft_split(head->command_name, ' ');
		head->split = cmd_split;
		head = head->next;
	}
}
