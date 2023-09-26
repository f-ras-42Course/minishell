/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/20 19:42:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "lexer.h"
# include "parser.h"

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
	FILE,
	INVALID_SYNTAX,
	NONE
}	t_node_type;

typedef	enum e_error_type
{
	NONE,
	MALLOC_FAILED
}	t_error_type;


bool	proper_start(int argc, char **argv);
char	*init_prompt(const char *prompt);
bool	valid_input(const char *input);
void	execute(char *input, char **envp);

#endif