/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 13:26:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:26:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		count;

	count = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*fill_str(int digits, char *str, int n, int index)
{
	digits--;
	if (n == 0)
	{
		str = ft_strdup("0\0");
		return (str);
	}
	if (n < 0)
	{
		str[index++] = '-';
		n *= -1;
		digits++;
	}
	while (n)
	{
		str[digits--] = (n % 10) + 48;
		n = n / 10;
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = count_digits(n);
	if (n < 0)
		str = (char *)malloc((digits + 2));
	else
		str = (char *)malloc((digits + 1));
	if (!str)
		return (NULL);
	return (str = fill_str(digits, str, n, 0));
}
