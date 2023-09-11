/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:41:59 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 14:06:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares up to n bytes between s1 and s2. Returns 0 if equal. */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			index;
	int				sum;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	index = 0;
	sum = 0;
	while (index < n)
	{
		if (a[index] != b[index])
		{
			sum = a[index] - b[index];
			return (a[index] - b[index]);
		}
		index++;
	}
	return (sum);
}
