/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:05:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/24 15:07:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the string ’s’ to the given file descriptor
followed by a newline. */

void	ft_putendl_fd(char *s, int fd)
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
		write(fd, "\n", 1);
	}
}
