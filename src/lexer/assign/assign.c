/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 13:22:14 by fras          #+#    #+#                 */
/*   Updated: 2023/11/09 15:30:53 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*asign_value(char *line, int *i)
{
	char		*value;

	while (line[*i] == ' ')
		*i++;
	if (line[*i])
	{
		if (is_quote(line[*i]))
		{
			if (!quote_is_closed(line[*i]))
				return (print_error(line[*i]), line[*i]);
			*i += assign_quote(line[*i], &value);
			return (value);
		}
		if (special_case(line[*i]))
		{
			*i += assign_special_case(line[*i], &value);
			return (value);
		}
		i += assign_word(line[*i], &value);
		return (value);
	}
	return ("");
}