/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:45:56 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 17:46:56 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c < 65 || (c > 90 && c < 97) || c > 122)
		return (0);
	else
		return (1);
}
