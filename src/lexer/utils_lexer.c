/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_lexer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 19:15:55 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 13:48:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(char *string)
{
	write(STDERR_FILENO, string, ft_strlen(string));
}
