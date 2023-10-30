/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:52:57 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/29 14:50:46 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *error)
{
	perror(error);
	exit(1);
}

void	free_cmd_paths(char **cmd_paths)
{
	int	i;

	i = 0;
	if (!cmd_paths)
		return ;
	while (cmd_paths[i])
	{
		free(cmd_paths[i]);
		i++;
	}
	free(cmd_paths);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putendl_fd("Error, please enter 4 arguments", 1);
		exit(EXIT_FAILURE);
	}
	pipex.cmd_args = &argv[2];
	pipex.in_file = open(argv[1], O_RDONLY, 0777);
	if (pipex.in_file < 0)
		error_msg("error");
	pipex.out_file = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.out_file < 0)
		error_msg("error");
	if (!update_path(env, &pipex))
		error_msg("Unable to get CMD paths");
	execute_pipex(&pipex);
	free_cmd_paths(pipex.cmd_paths);
}
