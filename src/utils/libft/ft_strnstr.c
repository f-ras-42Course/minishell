/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:08:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:26:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, int len)
{
	int		i;
	int		n_len;
	char	*sub;

	i = 0;
	sub = "a";
	if ((stack == NULL || stack[0] == '\0')
		&& ft_strncmp(stack, needle, ft_strlen(needle)) != 0)
		return (NULL);
	if (needle[0] == '\0' || ft_strlen(needle) <= 0 || ft_strlen(stack) == 0)
		return ((char *)stack);
	n_len = ft_strlen(needle);
	while (i < ft_strlen(stack) && i < len && (i + n_len - 1) < len)
	{
		sub = ft_substr(stack, i, n_len);
		if (ft_strncmp(sub, needle, n_len) == 0)
		{
			free(sub);
			return ((char *)&stack[i]);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
