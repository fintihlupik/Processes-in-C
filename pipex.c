/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:44:33 by pterekho          #+#    #+#             */
/*   Updated: 2024/06/04 18:46:29 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **av, char **envp, int *fd)
{
	int	outfd;

	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (access(av[4], R_OK | W_OK) == -1)
		print_error("pipex: %s: %s\n", av[4], strerror(13));
	if (outfd == -1)
		perror_exit();
	if (dup2(outfd, STDOUT_FILENO) == -1)
		perror("");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("");
	close(fd[1]);
	close(outfd);
	ft_exec(av[3], envp);
	perror_exit();
}

void	child(char **av, char **envp, int *fd)
{
	int	infd;

	infd = open(av[1], O_RDONLY, 0644);
	if (access(av[1], R_OK) != 0)
		print_error("pipex: %s: %s\n", av[1], strerror(13));
	if (infd == -1)
	{
		print_error("pipex: %s: %s\n", av[1], strerror(2));
		exit(EXIT_FAILURE);
	}
	if (dup2(infd, STDIN_FILENO) == -1)
		perror("");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("");
	close(fd[0]);
	close(infd);
	ft_exec(av[2], envp);
	perror_exit();
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			perror_exit();
		if (pid == 0)
			child(av, envp, fd);
		else
		{
			if (wait(NULL) == -1)
				print_error("pipex: %s\n", strerror(errno));
			parent(av, envp, fd);
		}
	}
	else
	{
		ft_putstr_fd(strerror(22), 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
