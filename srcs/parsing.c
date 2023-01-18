/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:27:06 by fatilly           #+#    #+#             */
/*   Updated: 2021/11/10 00:44:49 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_cmd(char **av, t_pipex *p)
{
	p->cmd1 = ft_split(av[2], ' ');
	p->cmd2 = ft_split(av[3], ' ');
}

void	ft_search_line_path(char **envp, t_pipex *p)
{
	int		i;
	int		j;
	char	*line_path;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			j = ft_strlen(envp[i]);
			line_path = ft_substr(envp[i], 5, j);
		}
		i++;
	}
	p->path = ft_split(line_path, ':');
	free(line_path);
}

void	ft_parse_pipex(t_pipex *p, char **av, char **envp)
{
	ft_split_cmd(av, p);
	ft_search_line_path(envp, p);
	ft_add_backslash(p);
}
