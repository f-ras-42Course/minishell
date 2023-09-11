/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 08:52:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 15:44:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies up to size - 1 characters from the NUL-terminated string 
src to dst, NUL-terminating the result.
Returns the total length of the string they tried to create. */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	s_len;

	index = 0;
	s_len = 0;
	while (src[index] != '\0')
	{
		s_len++;
		index++;
	}
	index = 0;
	if (size != '\0')
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (s_len);
}
