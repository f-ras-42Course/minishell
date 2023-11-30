/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 14:25:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 16:10:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "lexer.h"
# include "definitions.h"

typedef struct s_exe	t_exe;

typedef struct s_file
{
	char				*filename;
	int					mode;
	char				*delimiter;
	struct s_file		*next;
}	t_file;

typedef struct s_cmd
{
	char			*command_name;
	char			**split;
	bool			output_redirection;
	bool			input_redirection;
	t_file			*outputs;
	t_file			*inputs;
	int				index;
	struct s_cmd	*next;
}	t_cmd;

void	run_parser(t_exe *executor, t_tokens *tokens, int index);
void	add_redir(t_file **redirections, char *name, int mode);
void	add_command(t_cmd **commands, int index);

t_cmd	*last_command(t_cmd *command);
t_cmd	*init_command(int index);

#endif
