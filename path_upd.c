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

int	update_path(char **env, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (env[i++])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->path = env[i] + 5;
			break ;
		}
	}
	if (!pipex->path)
		return (0);
	pipex->cmd_paths = ft_split(pipex->path, ':');
	return (1);
}

char	*get_cmd(t_pipex *pipex, char *cmd)
{
	char	**paths;
	char	*command_path;
	char	*complete_path;

	paths = pipex->cmd_paths;
	while (*paths)
	{
		command_path = ft_strjoin(*paths, "/");
		complete_path = ft_strjoin(command_path, cmd);
		if (access(complete_path, F_OK) == 0)
		{
			free(command_path);
			return (complete_path);
		}
		free(command_path);
		free(complete_path);
		paths++;
	}
	free_cmd_paths(pipex->cmd_paths);
	return (NULL);
}

void	run_cmd(t_pipex *pipex, int cmd_index)
{
	char	*path;
	char	*env[2];
	char	**list_cmd;

	env[0] = pipex->path;
	env[1] = NULL;
	list_cmd = ft_split(pipex->cmd_args[cmd_index], ' ');
	path = get_cmd(pipex, list_cmd[0]);
	if (!path)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	if (execve(path, list_cmd, env) == -1)
	{
		perror("Error executing command");
	}
	free(path);
}
