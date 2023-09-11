/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 18:09:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/21 18:09:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function concatenates dst and src into dst */
/* It returns the length of the string it tried to create */
/* Dst will be not me modified if dst is already fully occupied */
/* meaning that that there's a null character in the first size-1 bytes */

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	size_t	dst_index;
	size_t	src_index;

	dst_index = 0;
	src_index = 0;
	while (dst[dst_index] != '\0' && dst_index < size)
		dst_index++;
	while (src[src_index] != '\0' && (dst_index + src_index + 1) < size)
	{
		dst[dst_index + src_index] = src[src_index];
		src_index++;
	}
	if (dst_index < size)
		dst[dst_index + src_index] = '\0';
	return (ft_strlen(src) + dst_index);
}
