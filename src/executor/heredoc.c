/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:21:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/29 16:38:57 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*read_heredoc_line(t_exe *executor)
{
	char	*input;
	char	*temp_input;

	input = readline("> ");
	temp_input = expand_string(executor, input);
	free(input);
	return (temp_input);
}

void	fill_heredoc_file(t_exe *executor, char *filename, t_file *input_file)
{
	char	*input;
	char	*line;
	int		file;

	file = open_file(filename, TRUNCATE);
	input = NULL;
	init_heredoc_signal_handler();
	while (1)
	{
		input = read_heredoc_line(executor);
		if (ft_strcmp(input, input_file->delimiter) || !input)
		{
			free(input);
			break ;
		}
		line = join_three_strs(input, NULL, "\n");
		write(file, line, ft_strlen(line));
		free(line);
		free(input);
	}
	close(file);
	signal(SIGINT, SIG_DFL);
}

void	start_heredoc(t_exe *executor, t_file *input_file)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		fill_heredoc_file(executor, input_file->filename, input_file);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		executor->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		executor->exit_code = 128 + WTERMSIG(status);
	if (executor->exit_code != 0)
		executor->here_doc_signaled = 1;
}

int	handle_heredocs(t_exe *executor)
{
	t_cmd		*head;
	t_file		*input_head;
	int			index;

	head = executor->commands_list;
	index = 0;
	ignore_signals();
	while (head != NULL)
	{
		input_head = head->inputs;
		while (input_head != NULL)
		{
			if (input_head->mode == HEREDOC2)
				start_heredoc(executor, input_head);
			input_head = input_head->next;
		}
		index++;
		head = head->next;
	}
	restore_signals();
	return (0);
}
