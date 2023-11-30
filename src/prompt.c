/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:27 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/11 17:24:21 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_prompt(const char *prompt)
{
	char	*input;

	input = readline(prompt);
	if (!input)
	{
		printf("\n");
		return (NULL);
	}
	while (!valid_input(input))
	{
		free (input);
		input = readline(prompt);
		if (!input)
		{
			printf("\n");
			return (NULL);
		}
	}
	add_history(input);
	return (input);
}

bool	valid_input(const char *input)
{
	while (*input == ' ')
		input++;
	if (!*input)
		return (false);
	return (true);
}
