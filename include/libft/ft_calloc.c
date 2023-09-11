/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:36:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 11:28:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates specified amount of memory and initializes it to zero */

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, nelem * elsize);
	return (m);
}
