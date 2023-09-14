/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:29 by fras          #+#    #+#                 */
/*   Updated: 2023/09/14 15:46:15 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	PIPE,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	APPEND_REDIRECTION,
	HEREDOC,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ENVIRONMENT_VARIABLE,
	EXIT_STATUS,
	COMMAND,
	ARGUMENT
}	t_token_type;

typedef struct s_tokens
{
}	t_tokens;

#endif