/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   word.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 14:15:03 by fras          #+#    #+#                 */
/*   Updated: 2023/11/14 14:54:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		assign_word(char *line, char **dest)
{
	int	i;

	i = 0;
	*dest = malloc(get_word_size(line) * sizeof(char) + 1);
	if (!*dest)
		return (-1);
	i += word_copy(line, *dest);
	return (i);
}

size_t	word_copy(char *word, char *dest)
{
	size_t	size;

	size = 0;
	while (*word && *word != ' ' && !is_special_case(*word))
	{
		*dest++ = *word++;
		size++;
	}
	*dest = '\0';
	return (size);
}

size_t	get_word_size(char *start)
{
	size_t	size;

	size = 0;
	while (start[size] && start[size] != ' ' && !is_special_case(start[size]))
		size++;
	return (size);
}
