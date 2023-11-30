/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/13 16:21:15 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	envp_size(t_exe *executor)
{
	t_envp	*head;
	int		len;

	head = executor->envp_list;
	len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return (len);
}

char	**convert_envp_to_char(t_exe *executor)
{
	char	**envp;
	char	*temp;
	t_envp	*head;
	int		i;

	head = executor->envp_list;
	envp = ft_malloc((envp_size(executor) + 1) * sizeof(char *));
	i = 0;
	while (head != NULL)
	{
		temp = join_three_strs(head->key, "=", head->value);
		envp[i++] = ft_strdup(temp);
		free(temp);
		head = head->next;
	}
	envp[i] = NULL;
	return (envp);
}
