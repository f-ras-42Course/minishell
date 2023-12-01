/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:37:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 00:36:04 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

char	*ft_strnstr(const char *stack, const char *needle, int len);
char	*join_three_strs(char *s1, char *s2, char *s3);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);

void	*ft_calloc(int nelem, int elsize);
void	ft_error(char *msg, int err_code);
void	ft_putstr_fd(char *s, int fd);
void	*ft_malloc(int size);

int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);

bool	ft_strcmp(char *s1, char *s2);

#endif