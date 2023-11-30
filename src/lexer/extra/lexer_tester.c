/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_tester.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 17:27:06 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 17:39:39 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "stdio.h"
// #include "string.h"

// char	*node_types(t_node_type type, char *dst);

// void	print_lexer(t_tokens *tokens)
// {
// 	int indexer = 0;
// 	char storage[50];

// 	while (tokens)
// 	{
// 		printf("[TOKEN: %d]\n"
// 				"[VALUE: %s]\n"
// 				"[NODE_TYPE: %s]\n\n"
// 				"----------------------\n\n", indexer++, tokens->value,
//				node_types(tokens->type, storage));
// 		tokens = tokens->next;
// 	}
// }

// char	*node_types(t_node_type type, char *dst)
// {
// 	if (type == PIPE)
// 		return (strcpy(dst, "PIPE"));
// 	if (type == INPUT_REDIRECTION)
// 		return (strcpy(dst, "INPUT_REDIRECTION"));
// 	if (type == OUTPUT_REDIRECTION)
// 		return (strcpy(dst, "OUTPUT_REDIRECTION"));
// 	if (type == APPEND_REDIRECTION)
// 		return (strcpy(dst, "APPEND_REDIRECTION"));
// 	if (type == HEREDOC)
// 		return (strcpy(dst, "HEREDOC"));
// 	if (type == STRING_LITERAL_SINGLE_QUOTE)
// 		return (strcpy(dst, "STRING_LITERAL_SINGLE_QUOTE"));
// 	if (type == STRING_LITERAL_DOUBLE_QUOTE)
// 		return (strcpy(dst, "STRING_LITERAL_DOUBLE_QUOTE"));
// 	if (type == COMMAND)
// 		return (strcpy(dst, "COMMAND"));
// 	if (type == ARGUMENT)
// 		return (strcpy(dst, "ARGUMENT"));
// 	if (type == FILENAME)
// 		return (strcpy(dst, "FILENAME"));
// 	if (type == FLAG)
// 		return (strcpy(dst, "FLAG"));
// 	if (type == NONE)
// 		return (strcpy(dst, "NONE"));
// 	if (type == UNKNOWN)
// 		return (strcpy(dst, "UNKNOWN"));
// 	return ("***NULLLLLLLL***");
// }
