/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:55:52 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:55:54 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	normal_exit(t_pipex *var, int (*fd)[2], int argc)
{
	close_pipes(var, fd, argc - var->param, argc);
	close(var->fd_to_read);
	close(var->fd_to_write);
	wait(NULL);
	if (var->bonus == 1)
		unlink(".bonus_tmp");
	free(fd);
	free(var);
}

void	emergency_exit(t_pipex *var, int (*fd)[2], int argc)
{
	close_pipes(var, fd, argc - var->param, argc);
	if (var->fd_to_read >= 0)
		close(var->fd_to_read);
	if (var->fd_to_write >= 0)
		close(var->fd_to_write);
	if (var->bonus == 1)
		unlink(".bonus_tmp");
	free(fd);
	free(var);
	exit (-1);
}
