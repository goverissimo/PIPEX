/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:53:07 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/28 17:53:55 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include "libft/libft.h"

# include  <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int access_file(const char *path, int mode);


typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		in_file;
	int		out_file;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

int update_path(char **env, t_pipex *pipex);
char	*get_cmd(t_pipex *pipex, char *cmd);
/*error handling*/
void error_msg(char *error);

#endif