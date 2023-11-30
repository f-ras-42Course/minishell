/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/30 11:34:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 15:36:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_exit_code(int code, t_cmd *command, int len)
{
	if (len == 2)
	{
		code = ft_atoi(command->split[1]);
		if (!code)
		{
			cmd_error("exit", ": numeric argument required\n");
			code = 2;
		}
	}
	if (code > 255)
		code = code % 256;
	return (code);
}

int	exit_shell(t_exe *executor, int code, t_cmd *command)
{
	int	i;

	i = 0;
	if (command)
	{
		redirect_input(command);
		redirect_output(command);
		while (command->split[i])
			i++;
	}
	if (i > 2)
	{
		cmd_error("exit", ": too many arguments\n");
		executor->exit_code = 1;
		return (-1);
	}
	code = check_exit_code(code, command, i);
	empty_executor(executor);
	exit(code);
	return (code);
}
