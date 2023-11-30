/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/28 12:41:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*join_expanded_str(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	char	*output;

	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	output = ft_malloc(sizeof(char) * (i + 2));
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
		output[i++] = s2[j++];
	j = 0;
	while (s3[j])
		output[i++] = s3[j++];
	output[i] = '\0';
	return (output);
}

void	track_quotes(char c, bool *single_quotes
	, bool *double_quotes, bool *single_in_double)
{
	if (c == '\'')
	{
		*single_quotes = !(*single_quotes);
		if (*double_quotes)
			*single_in_double = *single_quotes;
	}
	else if (c == '"')
		*double_quotes = !(*double_quotes);
}

int	needs_expansion(char *str, int i, int key_start_position)
{
	bool	single_quotes;
	bool	double_quotes;
	bool	single_in_double;

	single_quotes = false;
	double_quotes = false;
	single_in_double = false;
	while (str[i])
	{
		track_quotes(str[i], &single_quotes, &double_quotes, &single_in_double);
		if (str[i] == '$' && (!single_quotes || single_in_double))
		{
			key_start_position = i + 1;
			break ;
		}
		i++;
	}
	if (key_start_position == 0 || str[key_start_position] == '\0')
		return (0);
	return (key_start_position);
}

int	needs_expansion_heredoc(char *str, int i, int key_start_position)
{
	while (str[i])
	{
		if (str[i] == '$')
		{
			key_start_position = i + 1;
			break ;
		}
		i++;
	}
	if (key_start_position == 0 || str[key_start_position] == '\0')
		return (0);
	return (key_start_position);
}
