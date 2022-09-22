/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:30 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 12:12:10 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	open_files(t_pipex *var, int (*fd)[2], int argc, char **argv)
{
	var->infile = argv[1];
	var->outfile = argv[argc - 1];
	if (var->bonus == 1)
	{
		var->fd_to_read = open(".bonus_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
		var->fd_to_write = open(
				var->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		var->fd_to_read = open(var->infile, O_RDONLY);
		var->fd_to_write = open(var->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (var->fd_to_read < 0)
		error_handler(var, fd, argc, 5);
	if (var->fd_to_write < 0)
		error_handler(var, fd, argc, 6);
}
