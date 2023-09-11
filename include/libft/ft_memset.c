/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:39:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 14:43:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Sets the first n bytes of dest to the value c. 
The value of c is converted to an unsigned character. */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new;
	size_t			index;

	index = 0;
	new = s;
	while (index < n)
	{
		new[index] = (unsigned char)c;
		index++;
	}
	return (new);
}
