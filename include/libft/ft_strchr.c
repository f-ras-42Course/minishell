/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:54:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 15:00:23 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function finds the first occurence of character c and returns 
a pointer to the first occurence of c. */

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	if (str[index] == (char)c)
		return (&((char *) str)[index]);
	while (index < (ft_strlen(str) + 1))
	{
		if (str[index] == (char)c)
			return (&((char *) str)[index]);
		index++;
	}
	return (NULL);
}
