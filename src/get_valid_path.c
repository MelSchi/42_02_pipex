/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:56:17 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 14:41:32 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static void	get_path(char **env, t_pipex *var)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", ft_strlen(*env)) != NULL)
		{
			if (**env == 'P')
			{
				var->path = ft_strnstr(*env, "PATH=", ft_strlen(*env));
				var->path = ft_strtrim(var->path, "PATH=");
				break ;
			}
		}
		env++;
	}
	return ;
}

static void	gen_dir_list(t_pipex *var)
{
	int		i;
	char	*temp;

	i = 0;
	var->dir_list = ft_split(var->path, ':');
	free(var->path);
	while (var->dir_list[i] != NULL)
	{
		temp = ft_strjoin(var->dir_list[i], "/");
		free(var->dir_list[i]);
		var->dir_list[i] = temp;
		i++;
	}
}

static void	gen_valid_cmd_path(t_pipex *var)
{
	while (*var->dir_list)
	{
		var->valid_cmd_path = ft_strjoin(*var->dir_list, var->flagless_cmd);
		if (access(var->valid_cmd_path, X_OK) == 0)
		{
			free(*var->dir_list);
			return ;
		}
		var->dir_list++;
	}
	perror("Command or command path not valid");
	exit(-1);
}

void	get_valid_path(char **env, t_pipex *var)
{
	get_path(env, var);
	gen_dir_list(var);
	gen_valid_cmd_path(var);
}
