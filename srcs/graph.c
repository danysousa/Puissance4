/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:31:42 by dsousa            #+#    #+#             */
/*   Updated: 2014/03/09 16:48:21 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void		graph(t_env *e, int i, int j)
{
	if (e->graph)
	{
		if (e->board[i][j] == CHIP_P1)
			ft_putstr("\033[31m");
		if (e->board[i][j] == CHIP_P2)
			ft_putstr("\033[33m");
	}
	ft_putchar(e->board[i][j]);
	ft_putstr("\033[0m");
}
