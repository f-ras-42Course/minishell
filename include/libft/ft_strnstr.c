/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:08:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/08 12:33:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates the first occurrence of the needle in the stack. No more than 
len characters are searched. If needle is an empty, stack is returned; 
if needle is not in stack, NULL is returned.  Otherwise a pointer to the 
first character of the first occurrence of needle is returned */

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
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
