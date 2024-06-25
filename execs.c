/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:59:50 by pterekho          #+#    #+#             */
/*   Updated: 2024/06/01 16:30:23 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *cmd, char **envp)
{
	char	**paths;
	char	*command_path;
	int		i;
	char	*directory;

	i = 0;
	if (*envp == NULL && access(cmd, X_OK) == -1)
		perror_exit();
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		directory = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(directory, cmd);
		free(directory);
		if (access(command_path, X_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	free_arr(paths);
	print_error("pipex: %s: command not found\n", cmd);
	exit(EXIT_FAILURE);
}

char	**cmd_split(char *cmd)
{
	if (ft_strchr(cmd, 39))
		return (ft_split(cmd, 39));
	else if (ft_strchr(cmd, 34))
		return (ft_split(cmd, 34));
	else
		return (ft_split(cmd, 32));
}

void	ft_exec(char *command, char **envp)
{
	char	**cmd;
	char	*path;
	char	**args;

	args = ft_split(command, 32);
	cmd = NULL;
	if (access(command, X_OK) == 0)
	{
		if (execve(args[0], args, envp) == -1)
			perror_exit();
	}
	else
	{
		cmd = cmd_split(command);
		path = findpath(args[0], envp);
		if (!path)
		{
			free_arr(cmd);
			perror_exit();
		}
	}
	if (execve(path, cmd, envp) == -1)
		perror_exit();
}
