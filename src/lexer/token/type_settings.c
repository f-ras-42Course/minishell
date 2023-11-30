/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_settings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 18:13:12 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 19:51:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_type	validate_token(t_tokens *token, t_tokens *all_tokens, \
							t_node_type expect)
{
	if (expect == FILENAME && is_quote(*(token->value)))
	{
		remove_quotations(token->value);
		return (UNKNOWN);
	}
	if (expect == FILENAME && is_special_case(*(token->value)))
	{
		clear_tokens(&all_tokens);
		print_error(FILENAME_MISSING);
		return (ERROR);
	}
	if (expect == COMMAND && token->type == PIPE)
	{
		clear_tokens(&all_tokens);
		print_error(PIPE_UNLOGICAL);
		return (ERROR);
	}
	if (token->type == INPUT_REDIRECTION || token->type == OUTPUT_REDIRECTION \
		|| token->type == APPEND_REDIRECTION)
		return (FILENAME);
	if (token->type == COMMAND || token->type == ARGUMENT \
		|| token->type == FLAG || token->type == STRING_LITERAL_SINGLE_QUOTE
		|| token->type == STRING_LITERAL_DOUBLE_QUOTE)
		return (ARGUMENT);
	return (UNKNOWN);
}

t_node_type	set_type(t_tokens *tokens, t_node_type expected)
{
	if (is_same_values(tokens->value, "<"))
		return (INPUT_REDIRECTION);
	if (is_same_values(tokens->value, "<<"))
		return (HEREDOC);
	if (is_same_values(tokens->value, ">"))
		return (OUTPUT_REDIRECTION);
	if (is_same_values(tokens->value, ">>"))
		return (APPEND_REDIRECTION);
	if (is_same_values(tokens->value, "|"))
		return (PIPE);
	if (expected == ARGUMENT)
	{
		if (*(tokens->value) == '\'')
			return (STRING_LITERAL_SINGLE_QUOTE);
		if (*(tokens->value) == '\"')
			return (STRING_LITERAL_DOUBLE_QUOTE);
		if (*(tokens->value) == '-')
			return (FLAG);
		return (ARGUMENT);
	}
	if (expected == FILENAME)
		return (FILENAME);
	return (COMMAND);
}
