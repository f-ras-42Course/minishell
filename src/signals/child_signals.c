/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_signals.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 18:36:46 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/12 18:38:55 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	child_signal_handler(int signal_num)
{
	printf("\n");
	(void) signal_num;
}

void	init_child_signal_handler(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}
