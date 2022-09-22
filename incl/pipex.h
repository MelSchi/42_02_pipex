/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:57:06 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 16:32:40 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	**dir_list;
	char	**full_cmd;
	char	*path;
	char	*valid_cmd_path;
	char	*flagless_cmd;
	int		pid;
	int		index;
	int		i;
	int		argc;
	int		fd_to_read;
	int		fd_to_write;
	int		bonus;
	char	*line;
	char	*limiter;
	int		param;
	char	*infile;
	char	*outfile;
}	t_pipex;

void	init_t_pipex(t_pipex *var);
void	get_execve_param(const char *argv, t_pipex *var, char **env);
void	get_valid_path(char **env, t_pipex *var);
void	open_files(t_pipex *var, int (*fd)[2], int argc, char **argv);
void	read_from_file(t_pipex *var, int (*fd)[2], int argc);
void	pipe_into_file(t_pipex *var, int (*fd)[2], int argc);
void	pipe_in_between(t_pipex *var, int (*fd)[2], int argc);
void	open_pipes(t_pipex *var, int argc, int (*fd)[2]);
void	close_pipes(t_pipex *var, int (*fd)[2], int max, int argc);
void	ft_pipex(t_pipex *var, char **argv, char **env, int (*fd)[2]);

/* Error and Exit handling */
void	init_error_handler(int error_code);
void	error_handler(t_pipex *var, int (*fd)[2], int argc, int error_code);
void	normal_exit(t_pipex *var, int (*fd)[2], int argc);
void	emergency_exit(t_pipex *var, int (*fd)[2], int argc);

/* Get next line */
void	get_next_line_pipex(t_pipex *var);
int		ft_strlen_del(const char *s, char del);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif