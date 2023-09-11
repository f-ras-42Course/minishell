/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:07:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 17:10:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Converts lowercase character to uppercase character */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	return (c);
}
