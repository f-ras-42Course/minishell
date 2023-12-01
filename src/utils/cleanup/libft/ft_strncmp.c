/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:35:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:26:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	index;
	int	r;

	index = 0;
	r = 0;
	while (index < n && (*(s1 + index) || *(s2 + index)))
	{
		if (*(s1 + index) != *(s2 + index))
		{
			r = *((unsigned char *)s1 + index) - *((unsigned char *)s2 + index);
			break ;
		}
		index++;
	}
	return (r);
}
