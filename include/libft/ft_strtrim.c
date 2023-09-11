/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 07:59:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 23:11:31 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a copy of ’s1’ with the characters specified in ’set’ removed 
from the beginning and the end of the string. */

static int	check_set(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	last;
	size_t	first;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	first = 0;
	last = ft_strlen(s1) - 1;
	while (first < ft_strlen(s1))
	{
		if (!check_set(set, s1[first]))
			break ;
		first++;
	}
	while (last > 0)
	{
		if (!check_set(set, s1[last]))
			break ;
		last--;
	}
	return (ft_substr(s1, first, last - first + 1));
}

static int	check_set(char const *set, char c)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}
