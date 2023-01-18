/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:23:13 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/27 17:29:11 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_file(char *file, int nb)
{
	if (nb == 1)
	{
		if (access(file, F_OK))
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

void	ft_init_pipex(t_pipex *p)
{
	p->cmd1 = NULL;
	p->cmd2 = NULL;
	p->arglist1 = NULL;
	p->arglist2 = NULL;
	p->path = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;
	int		f1;
	int		f2;

	if (ac == 5)
	{
		ft_init_pipex(&p);
		f1 = ft_open_file(av[1], 1);
		f2 = ft_open_file(av[4], 0);
		ft_parse_pipex(&p, av, envp);
		ft_pipex(f1, f2, &p, envp);
	}
	else
	{
		ft_putstr_fd("Mauvais arguments\n", 2);
		return (1);
	}
}
