/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:25:17 by fras          #+#    #+#                 */
/*   Updated: 2023/12/01 17:17:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(t_error_type error, char *special_value)
{
	if (error == MALLOC_FAILED)
		error_output("minishell: malloc failed.\n");
	if (error == UNCLOSED_QUOTE)
		error_output("minishell: unclosed quotation detected.\n");
	if (error == PIPE_UNLOGICAL)
		error_output("minishell: syntax error near unexpected token `|'\n");
	if (error == FILENAME_MISSING || error == INVALID_SPECIAL_CASE)
	{
		error_output("minishell: syntax error near unexpected token `");
		error_output(special_value);
		error_output("'\n");
	}
}

void	error_output(char *string)
{
	write(STDERR_FILENO, string, fr_strlen(string));
}

char	*get_token_location_invalid_special_case(char *invalid_value)
{
	int	i;

	i = 0;
	if (*invalid_value == '<')
		while (invalid_value[i] == '<' && i != 2)
			i++;
	else if (*invalid_value == '>')
		while (invalid_value[i] == '>' && i != 2)
			i++;
	else if (*invalid_value == '|')
		i++;
	return (invalid_value + i);
}
