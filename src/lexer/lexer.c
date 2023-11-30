/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:26 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 13:47:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*lexer(char *line)
{
	t_tokens	*tokens;

	tokens = init_tokens(line);
	tokens = check_syntax(tokens);
	if (!tokens)
		return (NULL);
	set_token_types(tokens);
	if (!tokens)
		return (NULL);
	return (tokens);
}

t_tokens	*init_tokens(char *line)
{
	int			i;
	char 		*value;
	t_tokens	*tokens;
	t_tokens 	*node;

	i = 0;
	value = malloc_protection1(assign_value(line, &i), NULL);
	tokens = malloc_protection2(create_token(value), NULL);
	node = tokens;
	value = malloc_protection1(assign_value(line, &i), tokens);
	while (value && *value)
	{
		node = malloc_protection2(add_new_token(value, &node), tokens);
		value = malloc_protection1(assign_value(line, &i), tokens);
	}
	return (tokens);
}

t_tokens *check_syntax(t_tokens *tokens)
{
	t_tokens *ptr;

	ptr = tokens;
	while (ptr)
	{
		if (is_quote(*(ptr->value)) && ptr->value[1] == '\0')
		{
			clear_tokens(&tokens);
			print_error(UNCLOSED_QUOTE);
			return (NULL);
		}
		if (is_special_case(*(ptr->value)) && !is_quote(*(ptr->value)) \
			&& !valid_special_case(ptr->value))
		{
			clear_tokens(&tokens);
			print_error(INVALID_SPECIAL_CASE);
			return (NULL);
		}
		ptr = ptr->next;
	}
	return (tokens);
}

t_tokens	*set_token_types(t_tokens *token)
{
	t_tokens	*all_tokens;
	t_node_type	expected;

	all_tokens = token;
	expected = COMMAND;
	while (token && expected != ERROR)
	{
		token->type = set_type(token, expected);
		expected = validate_token(token, all_tokens, expected);
		token = token->next;
	}
	if (expected == FILENAME)
	{
		clear_tokens(&all_tokens);
		print_error(FILENAME_MISSING);
		return (NULL);
	}
	return (all_tokens);
}

t_node_type	validate_token(t_tokens *token, t_tokens *all_tokens, t_node_type expect)
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

char	*malloc_protection1(char *value, t_tokens *tokens)
{
	if (!value)
	{
		clear_tokens(&tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	return (value);
}

t_tokens	*malloc_protection2(t_tokens *ptr, t_tokens *tokens)
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
