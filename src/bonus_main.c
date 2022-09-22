/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:56:48 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 15:06:42 by mschiman         ###   ########.fr       */
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

	if ((ft_strncmp(argv[1], "here_doc", 8) == 0 && argc <= 5) || argc <= 4)
		init_error_handler(1);
	fd = malloc((argc - 2 - 1) * sizeof(*fd));
	if (!fd)
		init_error_handler(2);
	allocate_struct(&var, fd);
	var->argc = argc;
	var->bonus = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		var->bonus = 1;
	open_files(var, fd, argc, argv);
	if (var->bonus == 1)
	{
		var->limiter = argv[2];
		get_next_line_pipex(var);
		var->fd_to_read = open(".bonus_tmp", O_RDONLY);
	}
	set_struct_params(var);
	open_pipes(var, argc, fd);
	ft_pipex(var, argv, env, fd);
	normal_exit(var, fd, argc);
	return (0);
}
