/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 23:06:59 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/30 15:15:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_envp	*last_node_envp(t_envp *envp)
{
	t_envp	*temp;

	temp = envp;
	if (envp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_envp	*new_node_envp(char *key, char *value)
{
	t_envp	*node;

	node = malloc(sizeof(t_envp));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	add_node_envp(t_envp **envp, char *key, char *value)
{
	t_envp	*last;
	t_envp	*new;

	if (!key || !value)
		return ;
	new = new_node_envp(key, value);
	if (*envp != NULL && new != NULL)
	{
		last = last_node_envp(*envp);
		last->next = new;
	}
	else
		*envp = new;
}

char	**ft_split_paths(char *whole_str)
{
	char	**split_paths;
	int		index;
	char	*temp;

	index = 0;
	split_paths = ft_split(whole_str, ':');
	if (!split_paths)
		error_exit(NULL, "Malloc error");
	while (split_paths[index])
	{
		temp = join_three_strs(split_paths[index], NULL, "/");
		free(split_paths[index]);
		split_paths[index] = temp;
		index++;
	}
	split_paths[index] = NULL;
	free(whole_str);
	return (split_paths);
}

char	**get_paths(char **envp)
{
	char	*temp;
	char	**split_paths;

	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	temp = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	if (!temp)
		return (NULL);
	split_paths = ft_split_paths(temp);
	return (split_paths);
}
