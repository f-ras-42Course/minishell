/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:03:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 11:38:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function converts a str to int */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	convert(const char *str, int index, int n)
{
	int	sum;

	sum = 0;
	while (ft_isdigit(str[index]))
		sum = sum * 10 + str[index++] - 48;
	return (sum * n);
}

static int	find_start(const char *str)
{
	int	start;
	int	n;

	start = 0;
	n = 1;
	while ((str[start] >= 9 && str[start] <= 13) || str[start] == ' ')
		start++;
	if (str[start] == '-' || str[start] == '+')
	{
		if (str[start] == '-')
			n = -1;
		start++;
	}
	return (convert(str, start, n));
}

int	ft_atoi(const char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	if (str == NULL)
		return (ft_atoi(str));
	return (find_start(str));
}
