/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_executor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 15:56:22 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 12:20:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "builtins.h"

extern int	g_signal_code;

void	prepare_executor(t_exe *executor)
{
	executor->pids = ft_malloc((executor->command_count + 1) * sizeof(pid_t));
	executor->index = 0;
	executor->here_doc_signaled = 0;
	if (g_signal_code != 0)
		executor->exit_code = g_signal_code;
}

void	init_executor(t_exe *executor, char **envp)
{
	t_builtins	*builtins;
	int			size;

	size = 0;
	while (envp[size])
		size++;
	executor->exit_code = 0;
	executor->current_directory = get_current_directory();
	builtins = ft_malloc(7 * sizeof(t_builtins));
	builtins[0] = (t_builtins){"env", &print_env};
	builtins[1] = (t_builtins){"echo", &echo};
	builtins[2] = (t_builtins){"cd", &cd};
	builtins[3] = (t_builtins){"pwd", &print_current_directory};
	builtins[4] = (t_builtins){"export", &prepare_export};
	builtins[5] = (t_builtins){"unset", &prepare_unset};
	builtins[6] = (t_builtins){NULL, NULL};
	executor->builtins = builtins;
	executor->index = 0;
	init_envp(executor, envp);
}
