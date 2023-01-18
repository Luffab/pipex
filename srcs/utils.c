/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:47:14 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/27 17:29:50 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i] != 0)
		i++;
	return (i);
}

void	ft_add_backslash(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->path[i])
	{
		p->path[i] = ft_strjoin(p->path[i], "/");
		i++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free(t_pipex *p)
{
	if (p->cmd1)
		ft_free_split(p->cmd1);
	if (p->cmd2)
		ft_free_split(p->cmd2);
	if (p->path)
		ft_free_split(p->path);
	if (p->arglist1)
		ft_free_split(p->arglist1);
	if (p->arglist2)
		ft_free_split(p->arglist2);
}
