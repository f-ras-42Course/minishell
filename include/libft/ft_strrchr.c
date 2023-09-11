/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:21:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/28 09:20:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function finds the last occurence of character c.
It returns a pointer to the last occurence of c. */

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;

	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;
	while (str_len >= 0)
	{
		if (s[str_len] == (char)c)
			return (&((char *) s)[str_len + 1]);
		str_len--;
	}
	return (NULL);
}
