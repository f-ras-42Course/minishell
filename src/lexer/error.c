/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:25:17 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 19:55:08 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(t_error_type error)
{
	if (error == MALLOC_FAILED)
		error_output("MINISHELL ERROR: malloc failed.\n");
	if (error == UNCLOSED_QUOTE)
		error_output("MINISHELL ERROR: unclosed quotation detected.\n");
	if (error == INVALID_SPECIAL_CASE)
		error_output("MINISHELL ERROR: syntax error. " \
					"Check special characters.\n");
	if (error == PIPE_UNLOGICAL)
		error_output("MINISHELL ERROR: syntax error. " \
					"Expected command, received pipe.\n");
	if (error == FILENAME_MISSING)
		error_output("MINISHELL ERROR: syntax error. " \
					"Filename not defined for redirection.\n");
}

void	error_output(char *string)
{
	write(STDERR_FILENO, string, ft_strlen(string));
}
