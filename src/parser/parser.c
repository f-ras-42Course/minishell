/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 14:25:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 12:55:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_redirection(t_tokens *token, t_cmd *cmd_node)
{
	char	*filename;

	if (token->type == OUTPUT_REDIRECTION || token->type == APPEND_REDIRECTION)
	{
		filename = token->next->value;
		add_redir(&cmd_node->outputs, filename, token->type);
		cmd_node->output_redirection = true;
		return (true);
	}
	else if (token->type == INPUT_REDIRECTION || token->type == HEREDOC)
	{
		filename = token->next->value;
		add_redir(&cmd_node->inputs, filename, token->type);
		cmd_node->input_redirection = true;
		return (true);
	}
	return (false);
}

void	update_command_name(t_tokens *token, t_cmd *cmd_node)
{
	char	*temp;

	temp = ft_strdup(cmd_node->command_name);
	free(cmd_node->command_name);
	cmd_node->command_name = join_three_strs(temp, " ", token->value);
	free(temp);
}

void	run_parser(t_exe *executor, t_tokens *tokens, int index)
{
	t_cmd	*commands_list;
	t_cmd	*current_cmd;

	commands_list = NULL;
	add_command(&commands_list, index);
	current_cmd = last_command(commands_list);
	while (tokens)
	{
		if (parse_redirection(tokens, current_cmd) == true)
			tokens = tokens->next->next;
		else
		{
			if (tokens->type == PIPE)
			{
				add_command(&commands_list, index++);
				current_cmd = last_command(commands_list);
			}
			else if (tokens->type != FILENAME)
				update_command_name(tokens, current_cmd);
			tokens = tokens->next;
		}
	}
	executor->command_count = index;
	executor->commands_list = commands_list;
}
