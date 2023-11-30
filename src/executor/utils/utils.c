/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 15:07:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

bool	check_executable(char *command)
{
	if (ft_strnstr(command, "/", ft_strlen(command)))
	{
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
				return (true);
			else
			{
				cmd_error(command, ": Permission denied\n");
				exit(126);
			}
		}
		else
		{
			cmd_error(command, ": No such file or directory\n");
			exit(127);
		}
	}
	return (true);
}

char	*get_cmd_path(t_exe *executor, char *cmd, char **envp, int i)
{
	char	**paths;
	char	*path;

	paths = get_paths(envp);
	while (paths[i])
	{
		path = join_three_strs(paths[i], NULL, cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			empty_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	empty_array(paths);
	if (!check_executable(cmd))
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0 && ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	cmd_error(cmd, ": command not found\n");
	exit_shell(executor, 127, NULL);
	return (NULL);
}

int	open_file(char *filename, int mode)
{
	int	file;

	file = -1;
	if (mode == APPEND)
		file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mode == TRUNCATE)
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == READ)
		file = open(filename, O_RDONLY);
	if (file < 0)
		file_error(filename);
	return (file);
}

void	wait_for_all_child_processes(t_exe *executor)
{
	int	index;
	int	status;

	index = 0;
	while (executor->pids[index])
	{
		waitpid(executor->pids[index++], &status, 0);
		if (WIFEXITED(status))
			executor->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			executor->exit_code = 128 + WTERMSIG(status);
	}
}
