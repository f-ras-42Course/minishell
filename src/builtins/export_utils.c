/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 12:41:24 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 01:13:52 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	handle_key(t_exe *executor, char **key_split, char **value)
{
	if (ft_strlen(*value) > 0 && key_split)
	{
		export(executor, key_split[0], *value);
		free(*value);
		*value = ft_strdup("");
		empty_array(key_split);
	}
}

bool	is_valid_key(char *key)
{
	int	i;

	i = 1;
	if (ft_isdigit(key[0]) || key[0] == '_')
		return (false);
	if (key[i])
	{
		while (key[i])
		{
			if (!ft_isalnum(key[i]) && key[i] != '_')
				return (false);
			i++;
		}
	}
	return (true);
}

void	handle_value(char **value, char *str, int check)
{
	char	*temp;

	if (str && *value)
	{
		if (check == 1)
		{
			if (is_valid_key(str) == false)
			{
				cmd_error("export", ": not a valid identifier\n");
				return ;
			}
		}
		temp = *value;
		*value = join_three_strs(*value, " ", str);
		free(temp);
	}
}


void	export_all_keys(t_exe *executor, char **cmd, char **key_split, int i)
{
	char	*value;

	value = ft_strdup("");
	while (cmd[i])
	{
		if (ft_strnstr(cmd[i], "=", ft_strlen(cmd[i])))
		{
			if (key_split != NULL)
				handle_key(executor, key_split, &value);
			key_split = ft_split(cmd[i], '=');
			if (key_split[0] != NULL && key_split[1])
				handle_value(&value, key_split[1], 0);
		}
		else
			handle_value(&value, cmd[i], 1);
		i++;
	}
	if (key_split != NULL && ft_strlen(value) > 0)
	{
		export(executor, key_split[0], value);
		free(value);
	}
	empty_array(key_split);
}
