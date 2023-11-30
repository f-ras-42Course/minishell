/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:40:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/27 14:43:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	try_absolute_path(t_exe *executor, char *str)
{
	char	*home_path;
	char	*absolute_path;

	absolute_path = NULL;
	home_path = get_variable(executor, "HOME");
	while (*str)
	{
		if (*str == '/')
		{
			absolute_path = join_three_strs(home_path, NULL, str);
			if (chdir(absolute_path) == 0)
				return (true);
			break ;
		}
		str++;
	}
	return (false);
}

char	*find_cd_path(t_exe *executor, char *str)
{
	char	*path;

	path = NULL;
	if (ft_strcmp(str, "-"))
	{
		path = get_variable(executor, "OLDPWD");
		printf("%s\n", path);
	}
	else if (ft_strcmp(str, "~") || !str)
		path = get_variable(executor, "HOME");
	if (path == NULL)
		return (str);
	return (path);
}

void	update_directory_variables(t_exe *executor)
{
	char	*pwd;

	export(executor, "OLDPWD", executor->current_directory);
	free(executor->current_directory);
	pwd = get_current_directory();
	executor->current_directory = pwd;
	export(executor, "PWD", pwd);
}

void	cd(t_exe *executor, t_cmd *command)
{
	int		return_value;
	char	*path;

	path = command->split[1];
	return_value = chdir(find_cd_path(executor, path));
	if (return_value != 0)
	{
		if (try_absolute_path(executor, path))
			update_directory_variables(executor);
		else
		{
			executor->exit_code = 1;
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(path, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			perror("");
		}
	}
	else
		update_directory_variables(executor);
}
