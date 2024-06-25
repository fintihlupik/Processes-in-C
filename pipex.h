/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:33:57 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/06/23 13:33:57 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

void	perror_exit(void);
char	*findpath(char *cmd, char **envp);
void	ft_exec(char *av, char **envp);
void	child(char **av, char **envp, int *fd);
void	parent(char **av, char **envp, int *fd);
void	print_error(char *str, ...);
void	ft_putstr_fd(char const *s, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	free_arr(char **arr);

#endif