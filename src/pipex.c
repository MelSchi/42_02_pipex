/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:44 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:56:45 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_pipex(t_pipex *var, char **argv, char **env, int (*fd)[2])
{
	var->i = 2;
	if (var->bonus == 1)
		var->i = 3;
	while (var->i < var->argc - 1)
	{
		var->index = var->i - 2;
		if (var->bonus == 1)
			var->index = var->i - 3;
		var->pid = fork();
		if (var->pid == 0)
		{
			init_t_pipex(var);
			get_execve_param(argv[var->i], var, env);
			if (var->i == (var->param - 1))
				read_from_file(var, fd, var->argc);
			else if (var->i == var->argc - (var->param - (var->bonus + 1)))
				pipe_into_file(var, fd, var->argc);
			else
				pipe_in_between(var, fd, var->argc);
			if (execve(var->valid_cmd_path, var->full_cmd, NULL) == -1)
				error_handler(var, fd, var->argc, 8);
		}
		var->i++;
	}
}
