/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:02:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/01 11:12:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the string ’s’ to the given file descriptor */

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	if (s && fd)
	{
		while (index < ft_strlen(s))
		{
			write(fd, &s[index], 1);
			index++;
		}
	}
}
