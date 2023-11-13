/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 14:52:11 by fras          #+#    #+#                 */
/*   Updated: 2023/11/13 15:56:09 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*	steps in main:

	prompt <- init_prompt
	tokens <- lexer(prompt)
	data structure <- parse(tokens)
	modified data structure w/ variables <- expand(data)
	error code <- execute(modified data)
	check error code -> continue loop or return.
	
	Temporary skipping all steps and going from prompt -> execute

	Temp execute prototype: void	execute(char *input, char **envp);
	*/

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_tokens	*tokens;

	if (!proper_start(argc, argv))
		return (EXIT_FAILURE);
	while (1)
	{
		input = init_prompt("minishell$ ");
		if (!input)
			return (EXIT_SUCCESS);
		tokens = lexer(input, envp);
		clear_tokens(tokens);
		free(input);
	}
}

bool	proper_start(int argc, char **argv)
{
	if (argc == 1 && *argv)
		return (true);
	return (false);
}
