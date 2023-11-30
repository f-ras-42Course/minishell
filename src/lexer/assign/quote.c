/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 14:15:51 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 13:04:54 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	quote_is_closed(const char *str)
{
	char	quote_type;
	size_t	i;

	quote_type = *str;
	i = 1;
	while (str[i])
	{
		if (str[i] == quote_type)
			return (i);
		i++;
	}
	return (0);
}

size_t	get_quoted_string_literal(char *string, char *dest)
{
	char	quote_type;
	size_t	size;

	quote_type = *string;
	*dest = *string;
	size = 1;
	while (string[size] != quote_type)
	{
		dest[size] = string[size];
		size++;
	}
	dest[size++] = quote_type;
	dest[size] = '\0';
	return (size);
}

int		assign_quote(char *line, char **dest)
{
	int	i;

	i = 0;
	*dest = malloc(quote_is_closed(line) * sizeof(char) + 1);
	if (!*dest)
		return (-1);
	i += get_quoted_string_literal(line, *dest);
	return (i);
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

void	remove_quotations(char *string)
{
	char temp;

	while (1)
	{
		temp = *(string + 1);
		*string = temp;
		if (!temp)
			break ;
		string++;
	}
	*(string - 1) = '\0';
}
