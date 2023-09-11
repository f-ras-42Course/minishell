/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 07:25:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/31 14:51:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates with malloc and returns a new string, which is 
the result of the concatenation of ’s1’ and ’s2’. */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	str_len;
	int		index;
	int		second;

	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	index = 0;
	if (new_str == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		new_str[index] = s1[index];
		index++;
	}
	second = index;
	index = 0;
	while (s2[index] != '\0')
		new_str[second++] = s2[index++];
	new_str[second] = '\0';
	return (new_str);
}
