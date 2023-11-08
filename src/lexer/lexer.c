/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:26 by fras          #+#    #+#                 */
/*   Updated: 2023/11/07 18:28:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*lexer(char *line)
{
	t_tokens *token;
	
	token = init_tokens(line);
	set_token_types(token);
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
		node = malloc_protection(add_new_token(value, node), tokens);
		value = malloc_and_syntax_protections(assign_value(line, &i), tokens);
	}
	return (tokens);
}


// see special case
void		set_token_types(t_tokens *token)
{
	set_type(token, true);
	validate_token(token);
	if (token->type != )
		
	while (token->)
}

t_node_type	set_type(t_tokens *tokens, bool expecting_command)
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
	if ((ft_strncmp(tokens->value, "|", 1), ft_strncmp(tokens->value, "<", 1), \
			ft_strncmp(tokens->value, ">", 1)))
				return(INVALID_SYNTAX);
	if (!expecting_command)
	{
		if (*(tokens->value) == '\'')
				return (STRING_LITERAL_SINGLE_QUOTE);
		if (*(tokens->value) == '\"')
				return (STRING_LITERAL_DOUBLE_QUOTE);
		return (ARGUMENT);
	}
	if (command(tokens->value))
		return (COMMAND);
}

echo "$USER '$USER'fgodfg"
bool	command(char *str)
{
	return (is_same_values(str, "echo")
		|| is_same_values(str, "cd")
		|| is_same_values(str, "pwd")
		|| is_same_values(str, "export")
		|| is_same_values(str, "unset")
		|| is_same_values(str, "env")
		|| is_same_values(str, "exit"));
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

char	*basic_protections(char *ptr, t_tokens *tokens)
{
	if (!ptr)
	{
		clear_tokens(tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	if (*ptr == '\'' || *ptr == '\"')
	{
		clear_tokens(tokens);
		print_error(UNCLOSED_QUOTE);
		exit(UNCLOSED_QUOTE);
	}
	if(invalid_special_case(*ptr))
	{
		clear_tokens(tokens);
		print_error(INVALID_SPECIAL_CASE);
		exit(INVALID_SPECIAL_CASE);
	}
	return (ptr);
}

t_tokens	*malloc_and_syntax_protections(t_tokens *ptr, t_tokens *tokens)
{
	if (!ptr)
	{
		clear_tokens(tokens);
		print_error(MALLOC_FAILED);
		exit(MALLOC_FAILED);
	}
	return (ptr);
}

