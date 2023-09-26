/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:25:17 by fras          #+#    #+#                 */
/*   Updated: 2023/09/18 19:23:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(t_error_type error)
{
	if (error = MALLOC_FAILED);
		error_output("MINISHELL ERROR: malloc failed.\n");
}