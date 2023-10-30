/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:53 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/29 14:59:28 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_first_cmd(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_msg("Error forking process");
	if (pipex->pid1 == 0)
	{
		dup2(pipex->in_file, STDIN_FILENO);
		close(pipex->tube[0]);
		dup2(pipex->tube[1], STDOUT_FILENO);
		close(pipex->tube[1]);
		run_cmd(pipex, 0);
		exit(0);
	}
}

static void	execute_second_cmd(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_msg("Error forking process");
	if (pipex->pid2 == 0)
	{
		close(pipex->tube[1]);
		dup2(pipex->tube[0], STDIN_FILENO);
		dup2(pipex->out_file, STDOUT_FILENO);
		close(pipex->tube[0]);
		run_cmd(pipex, 1);
		exit(0);
	}
}

static void	wait_for_children(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

void	execute_pipex(t_pipex *pipex)
{
	if (pipe(pipex->tube) == -1)
		error_msg("Error creating pipe");
	execute_first_cmd(pipex);
	execute_second_cmd(pipex);
	wait_for_children(pipex);
}
