/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:52:00 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/24 15:00:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the character ’c’ to the given file descriptor. */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
