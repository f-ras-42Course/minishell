/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:18:52 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/31 14:11:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies up to n characters from src into dest */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			index;

	if (!dest && !src)
		return (NULL);
	csrc = (unsigned char *) src;
	cdest = (unsigned char *) dest;
	index = 0;
	while (index < n)
	{
		cdest[index] = csrc[index];
		index++;
	}
	return (cdest);
}
