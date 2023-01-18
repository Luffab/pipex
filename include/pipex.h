/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:29:48 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/27 16:48:44 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**arglist1;
	char	**arglist2;
	char	**path;
}				t_pipex;

int		ft_count_arg(char **av);
void	ft_parse_pipex(t_pipex *p, char **av, char **envp);
void	ft_add_backslash(t_pipex *p);
void	ft_pipex(int f1, int f2, t_pipex *p, char **envp);
void	ft_free(t_pipex *p);

#endif