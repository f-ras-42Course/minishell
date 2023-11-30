/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_signals.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:38:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/30 01:04:31 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	heredoc_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		exit(130);
	}
	else if (signal == SIGQUIT)
	{
		exit(131);
	}
}

void	init_heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal_handler);
	signal(SIGQUIT, heredoc_signal_handler);
}
