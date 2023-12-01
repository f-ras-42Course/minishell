/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 00:50:34 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executor.h"
# include <limits.h>
# include "expander.h"
# include "libft.h"

bool	parentprocess_builtins(t_exe *executor, t_cmd *command);
bool	childprocess_builtins(t_exe *executor, t_cmd *command);

void	export_all_keys(t_exe *executor, char **cmd, char **key_split, int i);
void	print_current_directory(t_exe *executor, t_cmd *command);
void	add_node_envp(t_envp **envp, char *key, char *value);
void	prepare_export(t_exe *executor, t_cmd *command);
void	prepare_unset(t_exe *executor, t_cmd *command);
void	export(t_exe *executor, char *key, char *value);
void	print_env(t_exe *executor, t_cmd *command);
void	init_envp(t_exe *executor, char **envp);
void	unset(t_exe *executor, char *key);
void	echo(t_exe *executor, t_cmd *command);
void	cd(t_exe *executor, t_cmd *command);

char	*join_three_strs(char *s1, char *s2, char *s3);

bool	detact_newline_flag(char *str);
bool	is_valid_key(char *key);

#endif