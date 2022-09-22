/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_excecve_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:05 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:56:07 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static void	extract_command(const char *argv, t_pipex *var)
{
	var->full_cmd = ft_split(argv, ' ');
	var->flagless_cmd = var->full_cmd[0];
}

void	get_execve_param(const char *argv, t_pipex *var, char **env)
{
	extract_command(argv, var);
	get_valid_path(env, var);
}
