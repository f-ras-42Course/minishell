/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:26 by fras          #+#    #+#                 */
/*   Updated: 2023/11/22 15:49:47 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*lexer(char *line)
{
	t_tokens	*token;

	token = init_tokens(line);
	set_token_types(token);
	return (token);
}

t_tokens	*init_tokens(char *line)
{
	int			i;
	char 		*value;
	t_tokens	*tokens;
	t_tokens 	*node;

	i = 0;
	value = malloc_and_syntax_protections(assign_value(line, &i), NULL);
	tokens = malloc_protection(create_token(value), NULL);
	node = tokens;
	value = malloc_and_syntax_protections(assign_value(line, &i), tokens);
	while (*value)
	{
		node = malloc_protection(add_new_token(value, &node), tokens);
		value = malloc_and_syntax_protections(assign_value(line, &i), tokens);
	}
	return (tokens);
}

void		set_token_types(t_tokens *token)
{
	t_tokens	*all_tokens;
	t_node_type	expected;

	all_tokens = token;
	expected = COMMAND;
	token->type = set_type(token, expected);
	expected = validate_token(token, all_tokens, expected);
	while (token->next)
	{
		token = token->next;
		token->type = set_type(token, expected);
		expected = validate_token(token, all_tokens, expected);
	}
}

t_node_type	validate_token(t_tokens *token, t_tokens *all_tokens, t_node_type expect)
{
	if (token->type == NONE)
	{
		clear_tokens(&all_tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	if (expect == COMMAND && token->type == PIPE)
	{
		clear_tokens(&all_tokens);
		print_error(SYNTAX_ERROR);
		exit(SYNTAX_ERROR);
	}
	if (token->type == INPUT_REDIRECTION || token->type == OUTPUT_REDIRECTION \
		|| token->type == APPEND_REDIRECTION)
		return (FILENAME);
	if (token->type == COMMAND || token->type == ARGUMENT \
		|| token->type == FLAG)
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

bool	is_same_values(const char *value1, const char *value2)
{
	int	i;

	i = 0;
	while (value1[i] == value2[i] && value1[i] && value2[i])
		i++;
	if (!value1[i] && !value2[i])
		return (true);
	return (false);
}

char	*malloc_and_syntax_protections(char *ptr, t_tokens *tokens)
{
	if (!ptr)
	{
		clear_tokens(&tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	if (*ptr == '\'' || *ptr == '\"')
	{
		clear_tokens(&tokens);
		print_error(UNCLOSED_QUOTE);
		exit(UNCLOSED_QUOTE);
	}
	if(!valid_special_case(ptr))
	{
		clear_tokens(&tokens);
		print_error(INVALID_SPECIAL_CASE);
		exit(INVALID_SPECIAL_CASE);
	}
	return (ptr);
}

t_tokens	*malloc_protection(t_tokens *ptr, t_tokens *tokens)
{
	if (!ptr)
	{
		clear_tokens(&tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	return (ptr);
}

bool	valid_special_case(char *ptr)
{

	if (is_same_values(ptr, "<"))
		return (true);
	if (is_same_values(ptr, "<<"))
		return (true);
	if (is_same_values(ptr, ">"))
		return (true);
	if (is_same_values(ptr, ">>"))
		return (true);
	if (is_same_values(ptr, "|"))
		return (true);
	return (false);
}
