/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:20:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 15:52:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function ’f’ to each character of the string ’s’, passing its
index as first argument to create a new string resulting from  applications 
of ’f’. Returns the string created from the results  of ’f’. */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	output = malloc(ft_strlen(s) + 1);
	if (output == NULL)
		return (NULL);
	while (index < ft_strlen(s))
	{
		output[index] = f(index, s[index]);
		index++;
	}
	output[index] = '\0';
	return (output);
}
