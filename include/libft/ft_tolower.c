/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:31:03 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 17:10:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Converts uppercase character to lowercase character */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	return (c);
}
