/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:12:33 by emcoutel          #+#    #+#             */
/*   Updated: 2014/03/09 17:07:48 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			check_horiz(t_env *e)
{
	int		c;
	int		tx;

	c = 0;
	tx = e->move_x;
	while (e->board[e->move_y][tx] == e->chip)
		tx--;
	tx++;
	while (tx < e->dim_x && e->board[e->move_y][tx] == e->chip && c < 4)
	{
		tx++;
		c++;
	}
	if (c == 4)
		return (e->player);
	return (0);
}

int			check_verti(t_env *e)
{
	int		c;
	int		ty;

	c = 0;
	ty = e->move_y;
	while (ty < e->dim_y && e->board[ty][e->move_x] == e->chip && c < 4)
	{
		ty++;
		c++;
	}
	if (c == 4)
		return (e->player);
	return (0);
}

int			check_slash(t_env *e)
{
	int		c;
	int		tx;
	int		ty;

	c = 0;
	tx = e->move_x;
	ty = e->move_y;
	while (tx >= 0 && ty < e->dim_y && e->board[ty][tx] == e->chip)
	{
		tx--;
		ty++;
	}
	tx++;
	ty--;
	while (tx < e->dim_x && ty >= 0 && e->board[ty][tx] == e->chip && c < 4)
	{
		tx++;
		ty--;
		c++;
	}
	if (c == 4)
		return (e->player);
	return (0);
}

int			check_bslash(t_env *e)
{
	int		c;
	int		tx;
	int		ty;

	c = 0;
	tx = e->move_x;
	ty = e->move_y;
	while (tx >= 0 && ty >= 0 && e->board[ty][tx] == e->chip)
	{
		tx--;
		ty--;
	}
	tx++;
	ty++;
	while (tx < e->dim_x && ty < e->dim_y && e->board[ty][tx] == e->chip
		&& c < 4)
	{
		tx++;
		ty++;
		c++;
	}
	if (c == 4)
		return (e->player);
	return (0);
}

int			check_board(t_env *e)
{
	int		ret;

	ret = check_horiz(e);
	if (!ret)
		ret = check_verti(e);
	if (!ret)
		ret = check_slash(e);
	if (!ret)
		ret = check_bslash(e);
	return (ret);
}
