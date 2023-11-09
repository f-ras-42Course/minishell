/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_assign.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 13:03:21 by fras          #+#    #+#                 */
/*   Updated: 2023/11/09 15:30:50 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_value_size(char *start)
{
	size_t	size;

	if (special_case(start[size]))
		
	while (start[size] && start[size] != ' ' && !special_case(start[size]))
		size++;
	return (size);
}

size_t	word_copy(char *word, char *dest)
{
	size_t	size;

	size = 0;
	while (*word && *word != ' ' && !special_case(*word));
	{
		*dest++ = *word++;
		size++;
	}
	*dest = '\0';
	return (size);
}

size_t	quote_is_closed(const char *str)
{
	char	quote_type;
	size_t	i;

	quote_type = *str;
	i = 1;
	while (str[i])
	{
		if (str[i] == quote_type)
			return (i - 1);
		i++;
	}
	return (0);
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
