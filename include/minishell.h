/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by fras	         #+#    #+#               */
/*   Updated: 2023/11/30 16:06:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "definitions.h"
# include "lexer.h"
# include "parser.h"
# include "libft.h"
# include "definitions.h"
# include "signals.h"
# include "executor.h"
# include "lexer.h"
# include "parser.h"

char	*init_prompt(const char *prompt);

void	print_lexer(t_tokens *tokens);
bool	proper_start(int argc, char **argv);
bool	valid_input(const char *input);
void	print_error(t_error_type error, char *special_value);

#endif