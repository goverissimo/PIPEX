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

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putendl_fd("Error, please enter 5 arguments", 1);
		exit(EXIT_FAILURE);
	}
	pipex.cmd_args = &argv[2];
	pipex.in_file = open(argv[1], O_RDONLY);
	if (pipex.in_file < 0)
		error_msg("error");
	pipex.out_file = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.out_file < 0)
		error_msg("error");
	if (!update_path(env, &pipex))
		error_msg("Unable to get CMD paths");
	execute_pipex(&pipex);
}
