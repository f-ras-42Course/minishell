/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 13:22:14 by fras          #+#    #+#                 */
/*   Updated: 2023/09/20 19:04:02 by fras          ########   odam.nl         */
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
		if ((line[*i] == '\'' || line[*i] == '\"'))
		{
			if (quote_is_closed(line[*i]))
			{
				*i += assign_quote(line[*i], &value);
				return (value);
			}
			*i++;
		}
		value = malloc(get_word_size(line + *i) * sizeof(char) + 1);
		if (!value)
			return (NULL);
		*i += word_copy(line + *i, value);
		return (value);
	}
	return ("");
}

size_t	get_word_size(char *start)
{
	size_t	size;

	while (start[size] && start[size] != ' ')
		size++;
	return (size);
}

size_t	word_copy(char *word, char *dest)
{
	size_t	size;

	size = 0;
	while (*word && *word != ' ')
	{
		*word++ = *dest++;
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

int	assign_quote( char *line, char **dest)
{
	int i;

	i = 2;
	*dest = malloc(quote_is_closed(line[i]) + 1);
	if (!*dest)
		return (-1);
	i += get_string_literal(line[i + 1], *dest);
	return (i);
}
