/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 12:52:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:27:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(int size)
{
	void	*output;

	output = malloc(size);
	if (!output)
		ft_error("Malloc failed\n", errno);
	return (output);
}
