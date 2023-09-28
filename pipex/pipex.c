/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:10:53 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/28 18:01:49 by gverissi         ###   ########.fr       */
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
	if (!pipex->cmd_paths)
		return (0);
	return (1);
}

/*TODO: CHECK FREES*/
char	*get_cmd(t_pipex *pipex, char *cmd)
{
	char	*command;
	char	**paths;

	paths = pipex->cmd_paths;
	while (*paths)
	{
		command = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(command, F_OK) == 0)
		{
			return (command);
		}
		free(command);
		paths++;
	}
	return (NULL);
}
