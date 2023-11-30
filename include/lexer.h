/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/14 12:10:29 by fras          #+#    #+#                 */
/*   Updated: 2023/11/30 15:35:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

// Lexer

t_tokens	*lexer(char *line);
t_tokens	*init_tokens(char *line);
t_tokens 	*check_syntax(t_tokens *tokens);
t_tokens	*set_token_types(t_tokens *token);
t_node_type	validate_token(t_tokens *token, t_tokens *all_tokens, t_node_type expect);
t_node_type	set_type(t_tokens *tokens, t_node_type expected);
bool		is_command(char *str);
bool		is_same_values(const char *value1, const char *value2);
char		*malloc_protection1(char *value, t_tokens *tokens);
t_tokens	*malloc_protection2(t_tokens *ptr, t_tokens *tokens);
bool		valid_special_case(char *ptr);

// Tokens

t_tokens	*create_token(char *value);
t_tokens	*add_new_token(char *value, t_tokens **prev);
void		clear_tokens(t_tokens **node);

// Utils

void		error_output(char *string);

// Assign

char		*assign_value(char *line, int *i);

// Quote

size_t		quote_is_closed(const char *str);
size_t		get_quoted_string_literal(char *string, char *dest);
int			assign_quote(char *line, char **dest);
bool		is_quote(char c);
void		remove_quotations(char *string);

// Utils ASSIGN

size_t		get_value_size(char *start);
size_t		quote_is_closed(const char *str);
size_t		get_string_literal(char *string, char *dest);

// Word

int			assign_word(char *line, char **dest);
size_t		word_copy(char *word, char *dest);
size_t		get_word_size(char *start);


// Special case

int			assign_special_case(char *line, char **dest);
size_t		special_case_copy(char *line, char *dest);
size_t		get_special_case_size(char *start);
bool		is_special_case(char c);

#endif