/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:23 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:56:24 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	init_t_pipex(t_pipex *var)
{
	var->dir_list = NULL;
	var->path = NULL;
	var->valid_cmd_path = NULL;
	var->full_cmd = NULL;
	var->flagless_cmd = NULL;
}

static void	allocate_struct(t_pipex **var, int (*fd)[2])
{
	*var = (t_pipex *)malloc(sizeof(t_pipex));
	if (!*var)
	{
		free(fd);
		init_error_handler(3);
	}
}

static void	set_struct_params(t_pipex *var)
{
	var->index = 0;
	var->param = 3;
	if (var->bonus == 1)
		var->param = 4;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*var;
	int		(*fd)[2];

	var = NULL;
	if (argc != 5)
		init_error_handler(1);
	fd = malloc((argc - 2 - 1) * sizeof(*fd));
	if (!fd)
		init_error_handler(2);
	allocate_struct(&var, fd);
	var->bonus = 0;
	var->argc = argc;
	open_files(var, fd, argc, argv);
	set_struct_params(var);
	open_pipes(var, argc, fd);
	ft_pipex(var, argv, env, fd);
	normal_exit(var, fd, argc);
	return (0);
}
