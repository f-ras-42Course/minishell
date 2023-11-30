/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 12:41:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 14:09:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	handle_key(t_exe *executor, char **split_key, char **value)
{
	if (ft_strlen(*value) > 0)
	{
		export(executor, split_key[0], *value);
		free(*value);
		*value = ft_strdup("");
		empty_array(split_key);
	}
}

void	handle_value(char **value, char *str)
{
	char	*temp;

	temp = *value;
	*value = join_three_strs(*value, " ", str);
	free(temp);
}

void	export_all_keys(t_exe *executor, char **cmd_split, int i)
{
	char	**split_key;
	char	*value;

	value = ft_strdup("");
	split_key = NULL;
	while (cmd_split[i])
	{
		if (ft_strnstr(cmd_split[i], "=", ft_strlen(cmd_split[i])))
		{
			if (split_key != NULL)
				handle_key(executor, split_key, &value);
			split_key = ft_split(cmd_split[i], '=');
			handle_value(&value, split_key[1]);
		}
		else
			handle_value(&value, cmd_split[i]);
		i++;
	}
	if (split_key != NULL && ft_strlen(value) > 0)
	{
		export(executor, split_key[0], value);
		free(value);
	}
	empty_array(split_key);
}
