/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:52:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/12/01 16:45:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"

void	check_filename_variable(t_exe *executor, t_file *file)
{
	char	*temp;
	char	*str;
	char	*value;

	if (file->filename[0] == '$')
	{
		temp = ft_strdup(file->filename);
		free(file->filename);
		str = ft_substr(temp, 1, ft_strlen(temp));
		value = get_variable(executor, str);
		file->filename = value;
		free(str);
		free(temp);
	}
}

void	redirect_output(t_exe *executor, t_cmd *command)
{
	int		file;
	t_file	*head;

	if (command->output_redirection == false)
		return ;
	head = command->outputs;
	while (head != NULL)
	{
		check_filename_variable(executor, head);
		if (head->mode == TRUNCATE)
			file = open_file(head->filename, TRUNCATE);
		else
			file = open_file(head->filename, APPEND);
		dup2(file, STDOUT_FILENO);
		close(file);
		head = head->next;
	}
}

void	redirect_input(t_exe *executor, t_cmd *command)
{
	int		file;
	t_file	*head;

	if (command->input_redirection == false)
		return ;
	head = command->inputs;
	while (head != NULL)
	{
		check_filename_variable(executor, head);
		file = open_file(head->filename, READ);
		dup2(file, READ);
		if (head->next != NULL)
			close(file);
		head = head->next;
	}
}
