/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:37 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:56:38 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	open_pipes(t_pipex *var, int argc, int (*fd)[2])
{
	while (var->index < argc - var->param)
	{
		if (pipe(fd[var->index]) == -1)
			error_handler(var, fd, argc, 9);
		var->index++;
	}
}

void	close_pipes(t_pipex *var, int (*fd)[2], int max, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < 2)
		{
			if (close(fd[i][j]) == -1)
				error_handler(var, fd, argc, 4);
			j++;
		}
		i++;
	}
}

void	read_from_file(t_pipex *var, int (*fd)[2], int argc)
{
	if (dup2(var->fd_to_read, STDIN_FILENO) == -1)
		error_handler(var, fd, argc, 2);
	if (dup2(fd[var->index][1], STDOUT_FILENO) == -1)
		error_handler(var, fd, argc, 1);
	close_pipes(var, fd, argc - var->param, argc);
}

void	pipe_into_file(t_pipex *var, int (*fd)[2], int argc)
{
	if (dup2(fd[var->index - 1][0], STDIN_FILENO) == -1)
		error_handler(var, fd, argc, 1);
	if (dup2(var->fd_to_write, STDOUT_FILENO) == -1)
		error_handler(var, fd, argc, 3);
	close_pipes(var, fd, argc - var->param, argc);
}

void	pipe_in_between(t_pipex *var, int (*fd)[2], int argc)
{
	if (dup2(fd[var->index - 1][0], STDIN_FILENO) == -1)
		error_handler(var, fd, argc, 1);
	if (dup2(fd[var->index][1], STDOUT_FILENO) == -1)
		error_handler(var, fd, argc, 1);
	close_pipes(var, fd, argc - var->param, argc);
}
