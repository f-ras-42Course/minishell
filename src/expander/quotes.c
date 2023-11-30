/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 18:09:16 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/27 00:57:32 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*handle_quotes(char *str, char *output, int i, int j)
{
	char	inside_quote;
	int		len;

	len = ft_strlen(str);
	inside_quote = '\0';
	output = ft_malloc((len * sizeof(char)) + 1);
	while (i < len)
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (inside_quote == '\0')
				inside_quote = str[i];
			else if (inside_quote == str[i])
				inside_quote = '\0';
			else
				output[j++] = str[i];
		}
		else
			output[j++] = str[i];
		i++;
	}
	output[j] = '\0';
	return (output);
}
