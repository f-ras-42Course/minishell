/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:27:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 14:00:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Scans the first n bytes of s for the first instance of c. Both c 
and s are interpreted as unsigned char. Returns a pointer to the matching
byte or NULL if c wasn't found */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (unsigned char)(c))
			return (&str[index]);
		index++;
	}
	return (NULL);
}
