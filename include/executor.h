/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/30 15:34:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "signals.h"
# include "parser.h"

# define READ 0
# define WRITE 1
# define INPUT 0
# define OUTPUT 1
# define TRUNCATE 2
# define APPEND 3
# define HEREDOC2 4
# define QUIT 1

extern int					g_signal_code;
typedef struct s_builtins	t_builtins;
typedef struct s_file		t_file;
typedef struct s_cmd		t_cmd;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_exe
{
	int				command_count;
	int				exit_code;
	int				fds[2];
	int				input_fd;
	int				index;
	int				status;
	int				here_doc_signaled;
	char			*current_directory;
	char			*input;
	char			**paths;
	t_builtins		*builtins;
	pid_t			*pids;
	t_cmd			*commands_list;
	t_envp			*envp_list;
}	t_exe;

typedef struct s_builtins
{
	char	*command;
	void	(*function)(t_exe *, t_cmd *);
}	t_builtins;

void	add_command_node(t_cmd **commands, char *command_line_split, int index);
void	init_executor(t_exe *executor, char **envp);
void	divide_command_in_redirections(t_cmd *node, char *command, int i);
void	wait_for_all_child_processes(t_exe *executor);
void	here_doc(t_file *head, char *delimiter);
void	add_redirection(t_file **filenames, char *name, int mode);
void	temp_parser(t_exe *executor, char *input);
void	cmd_error(char *cmd, char *error_message);
void	error_exit(char *command, char *msg);
void	file_error(char *filename);
void	free_redirection(t_file *node);
void	free_command_list(t_exe *executor);
void	ft_error(char *msg, int err_code);
void	prepare_executor(t_exe *executor);
void	redirect_output(t_cmd *command);
void	reset_executor(t_exe *executor);
void	empty_executor(t_exe *executor);
void	run_executor(t_exe *executor);
void	redirect_input(t_cmd *command);
void	empty_array(char **arr);

char	*get_cmd_path(t_exe *executor, char *cmd, char **envp, int i);
char	**convert_envp_to_char(t_exe *executor);
char	**ft_split_paths(char *whole_str);
char	*get_current_directory(void);
char	**get_paths(char **envp);
char	*expand_string(t_exe *executor, char *str);
char	**ft_split_args(char *s);
char	*get_next_line(int fd);
char	**manual_envp(void);

int		exit_shell(t_exe *executor, int code, t_cmd *command);
int		open_file(char *filename, int mode);
int		handle_heredocs(t_exe *executor);
int		search_newline(char *s);
int		ctrl_d(t_exe *executor);

bool	check_builtin(t_exe *executor, t_cmd *command);
bool	ft_strcmp(char *s1, char *s2);

#endif
