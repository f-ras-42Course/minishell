/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:29 by fras          #+#    #+#                 */
/*   Updated: 2023/09/18 18:14:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef struct s_tokens
{
	t_node_type	type;
	char		*value;
	t_tokens	*next;
}	t_tokens;

// Utils

t_tokens	*lexer_new_node(void *type, void *value);


#endif