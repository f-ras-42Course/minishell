/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variables.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 14:13:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/28 00:31:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*find_variable_name(char *str, int i)
{
	char	*key;
	int		start;
	int		len;

	start = i;
	len = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\0'
		&& str[i] != '"' && str[i] != '\'')
	{
		len++;
		i++;
	}
	key = ft_substr(str, start, len);
	return (key);
}

char	*get_variable(t_exe *executor, char *key)
{
	t_envp	*head;
	char	*exit_code;

	if (ft_strcmp("?", key))
	{
		exit_code = ft_itoa(executor->exit_code);
		return (exit_code);
	}
	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
