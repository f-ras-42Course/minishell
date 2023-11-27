/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:34:05 by fras          #+#    #+#                 */
/*   Updated: 2023/11/27 17:49:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

typedef enum e_node_type
{
	PIPE,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	APPEND_REDIRECTION,
	HEREDOC,
	STRING_LITERAL_SINGLE_QUOTE,
	STRING_LITERAL_DOUBLE_QUOTE,
	COMMAND,
	ARGUMENT,
	FILENAME,
	FLAG,
	NONE,
	UNKNOWN,
	UNCLOSED_QUOTATION,
	INVALID_SPECIAL
}	t_node_type;

typedef	enum e_error_type
{
	UNCLOSED_QUOTE,
	INVALID_SPECIAL_CASE,
	UNKNOWN_COMMAND,
	SYNTAX_ERROR,
	MALLOC_FAILED
}	t_error_type;

typedef struct s_tokens
{
	t_node_type		type;
	char			*value;
	struct s_tokens	*next;
}	t_tokens;

#endif