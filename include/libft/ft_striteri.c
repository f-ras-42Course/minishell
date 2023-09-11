/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 15:36:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function ’f’ on each character of the string passed as argument, 
passing its index as first argument. Each character is passed by address 
to ’f’ to be modified if necessary. */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	if (s && f)
	{
		while (index < ft_strlen(s))
		{
			f(index, &s[index]);
			index++;
		}
	}
}
