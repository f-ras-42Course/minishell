/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_assign.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 13:03:21 by fras          #+#    #+#                 */
/*   Updated: 2023/11/20 16:56:17 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_value_size(char *start)
{
	size_t	size;

	size = 0;
	if (is_special_case(start[size]))
		
	while (start[size] && start[size] != ' ' && !is_special_case(start[size]))
		size++;
	return (size);
}

size_t	get_string_literal(char *string, char *dest)
{
	char	quote_type;
	size_t	size;

	size = 0;
	quote_type = *string;
	while (*string != quote_type)
	{
		*dest++ = *string++;
		size++;
	}
	*dest = '\0';
	return (size);
}
