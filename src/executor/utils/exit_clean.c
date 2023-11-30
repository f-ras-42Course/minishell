/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 14:39:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	cmd_error(char *cmd, char *error_message)
{
	char	*error_msg;

	error_msg = join_three_strs("minishell: ", cmd, error_message);
	if (!error_msg)
		error_exit(cmd, "Malloc error");
	ft_putstr_fd(error_msg, 2);
	free(error_msg);
}

void	file_error(char *filename)
{
	ft_putstr_fd("minishell: ", 2);
	perror(filename);
	exit(EXIT_FAILURE);
}

void	error_exit(char *command, char *msg)
{
	if (access(command, X_OK) == 0)
	{
		cmd_error(command, ": Is a directory\n");
		exit(126);
	}
	else
	{
		perror(msg);
		exit(errno);
	}
}
