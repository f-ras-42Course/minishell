/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 11:49:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 11:50:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (false);
		index++;
	}
	return (true);
}
