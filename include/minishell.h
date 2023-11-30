/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/29 16:04:18 by juvan-to      ########   odam.nl         */
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
# include "libft.h"
# include "definitions.h"
# include "signals.h"
# include "executor.h"
# include "lexer.h"
# include "parser.h"

char	*init_prompt(const char *prompt);

void	print_lexer(t_tokens *tokens);
void	print_error(t_error_type error);

bool	proper_start(int argc, char **argv);
bool	valid_input(const char *input);

#endif