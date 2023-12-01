/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:49:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:26:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the array of new strings resulting from the split, NULL if 
the allocation fails. */

static char		**arr(char const *s, char	**split, int count, char c);
static char		*word(char const *s, unsigned int start, int len);
static void		*free_arr(char	**split, int count);
static int		count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_malloc((count_words(s, c) + 1) * sizeof(char *));
	split = arr(s, split, 0, c);
	return (split);
}

/* Loops through s and fills the array with the found words */
static char	**arr(char const *s, char	**split, int count, char c)
{
	int		found;
	int		i;
	char	*w;

	found = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[found] != c && s[found])
			found++;
		if (found == i)
			i++;
		else
		{
			w = word(s, i, found - i);
			if (w == NULL)
				return (free_arr(split, count));
			split[count++] = w;
			i = found;
		}
		found = i;
	}
	split[count] = NULL;
	return (split);
}

/* Returns the substring using the starting index of s and its len */
static char	*word(char const *s, unsigned int start, int len)
{
	int		index;
	char	*word;

	index = 0;
	word = (char *)ft_malloc((len + 1) * sizeof(char));
	while (index < len && s[start] != '\0')
		word[index++] = s[start++];
	word[index] = '\0';
	return (word);
}

/* Counts how many words can be made after splitting */
static int	count_words(char const *s, char c)
{
	int	count;
	int	index;
	int	found;

	found = 0;
	count = 0;
	index = 0;
	while (index < ft_strlen(s))
	{
		while (s[found] != c && s[found])
			found++;
		if (found == index)
			index++;
		else
		{
			index = found;
			count++;
		}
		found = index;
	}
	return (count);
}

/* Frees the array in case of errors */
static void	*free_arr(char	**split, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(split[index]);
		index++;
	}
	free(split);
	return (NULL);
}
