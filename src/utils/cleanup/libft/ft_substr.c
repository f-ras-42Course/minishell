/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:36:07 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/23 12:22:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		index;
	char	*sub;

	index = 0;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len < 0)
		sub = (char *)ft_malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else if ((start + len) > ft_strlen(s))
		sub = (char *)ft_malloc(len * sizeof(char));
	else
		sub = (char *)ft_malloc((len + 1) * sizeof(char));
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}
