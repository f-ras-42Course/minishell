/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/30 17:08:16 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	run_builtin(t_exe *executor, t_cmd *command)
{
	int	i;

	i = 0;
	while (executor->builtins[i].command)
	{
		if (ft_strcmp(command->split[0], executor->builtins[i].command))
			executor->builtins[i].function(executor, command);
		i++;
	}
}

bool	parentprocess_builtins(t_exe *executor, t_cmd *command)
{
	if (ft_strcmp(command->split[0], "cd")
		|| ft_strcmp(command->split[0], "export")
		|| ft_strcmp(command->split[0], "unset")
	)
	{
		run_builtin(executor, command);
		return (true);
	}
	return (false);
}

bool	childprocess_builtins(t_exe *executor, t_cmd *command)
{
	if (ft_strcmp(command->split[0], "pwd")
		|| ft_strcmp(command->split[0], "env")
		|| ft_strcmp(command->split[0], "echo")
	)
	{
		run_builtin(executor, command);
		return (true);
	}
	return (false);
}

char	*get_current_directory(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	return (path);
}

void	print_current_directory(t_exe *executor, t_cmd *command)
{
	printf("%s\n", executor->current_directory);
	(void)command;
}
