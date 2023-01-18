/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:59:09 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/17 02:24:11 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(t_pipex *p, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (p->path[i])
	{
		path = ft_strjoin(p->path[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (cmd);
}

void	ft_child_one(int f1, t_pipex *p, int *end, char **envp)
{
	char	*path;

	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	path = ft_get_path(p, p->cmd1[0]);
	execve(path, p->cmd1, envp);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(p->cmd1[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

void	ft_child_two(int f2, t_pipex *p, int *end, char **envp)
{
	char	*path;

	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(f2);
	path = ft_get_path(p, p->cmd2[0]);
	execve(path, p->cmd2, envp);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(p->cmd2[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

void	ft_pipex(int f1, int f2, t_pipex *p, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		perror("Fork: ");
	if (child1 == 0)
		ft_child_one(f1, p, end, envp);
	waitpid(child1, &status, 0);
	child2 = fork();
	if (child2 < 0)
		perror("Fork: ");
	if (child2 == 0)
		ft_child_two(f2, p, end, envp);
	close(end[0]);
	close(end[1]);
	waitpid(child2, &status, 0);
	ft_free(p);
	if (status != 0)
		exit (127);
}
