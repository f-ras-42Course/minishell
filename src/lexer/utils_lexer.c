/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_lexer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 19:15:55 by fras          #+#    #+#                 */
/*   Updated: 2023/12/01 17:17:24 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_same_values(const char *value1, const char *value2)
{
	int	i;

	i = 0;
	while (value1[i] == value2[i] && value1[i] && value2[i])
		i++;
	if (!value1[i] && !value2[i])
		return (true);
	return (false);
}

char	*malloc_protection1(char *value, t_tokens *tokens)
{
	if (!value)
	{
		clear_tokens(&tokens);
		print_error(MALLOC_FAILED, NULL);
		exit(MALLOC_FAILED);
	}
	return (value);
}

t_tokens	*malloc_protection2(t_tokens *ptr, t_tokens *tokens)
{
	if (!ptr)
	{
		clear_tokens(&tokens);
		print_error(MALLOC_FAILED, NULL);
		exit(MALLOC_FAILED);
	}
	return (ptr);
}

size_t	fr_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
