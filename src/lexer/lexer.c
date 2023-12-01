/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:26 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 18:17:35 by fras          ########   odam.nl         */
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
	tokens = set_token_types(tokens);
	if (!tokens)
		return (NULL);
	return (tokens);
}

t_tokens	*init_tokens(char *line)
{
	int			i;
	char		*value;
	t_tokens	*tokens;
	t_tokens	*node;

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

t_tokens	*check_syntax(t_tokens *tokens)
{
	t_tokens	*ptr;

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
