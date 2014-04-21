/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:47:29 by dsousa            #+#    #+#             */
/*   Updated: 2014/03/09 16:48:29 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			ia_check_board(t_env *e)
{
	char	disk;

	e->search_x = 0;
	disk = 1;
	e->best_move[0] = 0;
	e->best_move[1] = 0;
	if (e->n_turn == 1 && e->board[0][e->dim_x / 2] == '.')
	{
		e->n_turn += 2;
		return (e->dim_x / 2);
	}
	while (e->search_x < e->dim_x)
	{
		if ((e->search_y = define_ty(e->search_x, e)) != -1)
		{
			ia_check_horiz(e, disk);
			ia_check_verti(e, disk);
			ia_check_slash(e, disk);
			ia_check_bslash(e, disk);
		}
		disk = disk == CHIP_P1 ? CHIP_P2 : CHIP_P1;
		e->search_x = disk == CHIP_P1 ? e->search_x + 1 : e->search_x;
		e->n_turn += 2;
	}
	return (e->best_move[0]);
}
