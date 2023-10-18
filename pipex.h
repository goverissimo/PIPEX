/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:53:07 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/29 15:00:18 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid1;
	int		tube[2];
	int		in_file;
	int		out_file;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
}t_pipex;

int		update_path(char **env, t_pipex *pipex);
char	*get_cmd(t_pipex *pipex, char *cmd);
void	run_cmd(t_pipex *pipex, int cmd_index);
void	execute_pipex(t_pipex *pipex);
void	error_msg(char *error);

#endif
