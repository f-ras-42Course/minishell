/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_case.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 14:16:49 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 19:09:57 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	assign_special_case(char *line, char **dest)
{
	int	i;

	i = 0;
	*dest = malloc(get_special_case_size(line) * sizeof(char) + 1);
	if (!*dest)
		return (-1);
	i += special_case_copy(line, *dest);
	return (i);
}

size_t	special_case_copy(char *line, char *dest)
{
	size_t	size;

	size = 0;
	while (is_special_case(*line) && !is_quote(*line))
	{
		*dest++ = *line++;
		size++;
	}
	*dest = '\0';
	return (size);
}

size_t	get_special_case_size(char *start)
{
	size_t	size;

	size = 0;
	while (is_special_case(start[size]) && !is_quote(start[size]))
		size++;
	return (size);
}

bool	is_special_case(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == '\'' || c == '\"');
}

bool	valid_special_case(char *ptr)
{
	if (is_same_values(ptr, "<"))
		return (true);
	if (is_same_values(ptr, "<<"))
		return (true);
	if (is_same_values(ptr, ">"))
		return (true);
	if (is_same_values(ptr, ">>"))
		return (true);
	if (is_same_values(ptr, "|"))
		return (true);
	return (false);
}
