/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:12:33 by emcoutel          #+#    #+#             */
/*   Updated: 2014/03/09 17:49:33 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int				define_ty(int tx, t_env *e)
{
	int		y;

	y = e->dim_y;
	while (y--)
	{
		if (e->board[y][tx] == '.')
			return (y);
	}
	return (-1);
}

void			ia_check_horiz(t_env *e, char disk)
{
	int		count;
	int		tx;

	count = 10;
	tx = e->search_x;
	e->board[e->search_y][e->search_x] = disk;
	while (e->board[e->search_y][tx] && e->board[e->search_y][tx] == disk)
		tx--;
	tx++;
	while (tx < e->dim_x && e->board[e->search_y][tx] == disk)
	{
		tx++;
		count *= 10;
	}
	if (disk == CHIP_P1)
		count *= 0.5;
	if (count > e->best_move[1])
	{
		e->best_move[0] = e->search_x;
		e->best_move[1] = count;
	}
	e->board[e->search_y][e->search_x] = '.';
}

void			ia_check_verti(t_env *e, char disk)
{
	int		count;
	int		ty;

	count = 10;
	e->board[e->search_y][e->search_x] = disk;
	ty = e->search_y;
	while (ty < e->dim_y && e->board[ty][e->search_x] == disk)
	{
		ty++;
		count *= 10;
	}
	if (disk == CHIP_P1)
		count *= 0.5;
	if (count > e->best_move[1])
	{
		e->best_move[0] = e->search_x;
		e->best_move[1] = count;
	}
	e->board[e->search_y][e->search_x] = '.';
}

void			ia_check_slash(t_env *e, char disk)
{
	int		count;
	int		ty;
	int		tx;

	count = 10;
	e->board[e->search_y][e->search_x] = disk;
	tx = e->search_x;
	ty = e->search_y;
	while (tx > 0 && ty < e->dim_y && e->board[ty][tx] == disk)
	{
		tx--;
		ty++;
	}
	tx++;
	ty--;
	while (tx < e->dim_x && ty > 0 && e->board[ty--][tx++] == disk && count < 4)
		count++;
	count = (disk == CHIP_P1) ? count * 0.5 : count;
	if (count > e->best_move[1])
	{
		e->best_move[0] = e->search_x;
		e->best_move[1] = count;
	}
	e->board[e->search_y][e->search_x] = '.';
}

void			ia_check_bslash(t_env *e, char disk)
{
	int		count;
	int		ty;
	int		tx;

	count = 10;
	e->board[e->search_y][e->search_x] = disk;
	tx = e->search_x;
	ty = e->search_y;
	while (tx > 0 && ty > 0 && e->board[ty][tx] == disk)
	{
		tx--;
		ty--;
	}
	tx++;
	ty++;
	while (tx < e->dim_x && ty < e->dim_y && e->board[ty++][tx++] == disk
		&& count < 4)
		count++;
	count = (disk == CHIP_P1) ? count * 0.5 : count;
	if (count > e->best_move[1])
	{
		e->best_move[0] = e->search_x;
		e->best_move[1] = count;
	}
	e->board[e->search_y][e->search_x] = '.';
}
