/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_tester.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 17:27:06 by fras          #+#    #+#                 */
/*   Updated: 2023/11/22 17:23:42 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

void	print_lexer(t_tokens *tokens)
{
	int indexer = 0;

	while (tokens)
	{
		printf("[TOKEN: %d]\n"\
				"[VALUE: %s]\n"
				"[NODE_TYPE: %s]\n\n"
				"----------------------\n\n", indexer++, tokens->value, node_types(token->types));
		tokens = tokens->next;
	}
}

char	*node_types(e_node_type *type)
{
	if (type == )
}