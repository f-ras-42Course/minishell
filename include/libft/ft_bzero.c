/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:02:18 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/31 11:23:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function erases the data in the n bytes of the memory starting at the 
location pointed to by s, by writing zeros ('\0') to that area */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			index;

	p = s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}
