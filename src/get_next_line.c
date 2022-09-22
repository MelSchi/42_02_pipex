/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:41:10 by mschiman          #+#    #+#             */
/*   Updated: 2022/02/08 15:06:59 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	get_next_line_pipex(t_pipex *var)
{
	char	*line;
	char	rd_char[2];
	int		found_nl;
	int		found_keyword;

	found_keyword = 0;
	ft_bzero(rd_char, 2);
	while (found_keyword == 0)
	{
		line = NULL;
		found_nl = 0;
		while (found_nl == 0)
		{
			if ((read(STDIN_FILENO, &rd_char[0], 1)) != 1)
				break ;
			if (rd_char[0] == '\n')
				found_nl = 1;
			line = ft_strjoin_gnl(line, rd_char);
		}
		if (ft_strncmp(var->limiter, line, ft_strlen(var->limiter)) != 0)
			write(var->fd_to_read, line, ft_strlen(line));
		else
			found_keyword = 1;
		free(line);
	}
}
