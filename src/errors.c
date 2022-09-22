/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:55:44 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/27 16:55:46 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	init_error_handler(int error_code)
{
	if (error_code == 1)
		perror("Wrong number of arguments in function call");
	if (error_code == 2)
		perror("Unable to allocate memory for fd");
	if (error_code == 3)
		perror("Unable to allocate memory for var");
	exit (-1);
}

void	error_handler(t_pipex *var, int (*fd)[2], int argc, int error_code)
{
	if (error_code == 1)
		perror("Error while duplicating fd");
	else if (error_code == 2)
		perror("Error while reading from file");
	else if (error_code == 3)
		perror("Error while writing to file");
	else if (error_code == 4)
		perror("Error while closing fd");
	else if (error_code == 5)
	{
		perror("File to read");
		free(var);
		free(fd);
		exit(-1);
	}
	else if (error_code == 6)
		perror("File to write");
	else if (error_code == 7)
		perror("Not enough arguments in function call");
	else if (error_code == 8)
		perror("Command could not be applied");
	else if (error_code == 9)
		perror("Could not create pipes");
	emergency_exit(var, fd, argc);
}
