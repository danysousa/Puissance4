/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:27:57 by emcoutel          #+#    #+#             */
/*   Updated: 2014/03/09 16:48:32 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void		ft_init_board(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	e->board = (char **) malloc(e->dim_y * sizeof(char *) + 1);
	while (i < e->dim_y)
	{
		j = 0;
		e->board[i] = (char *) malloc(e->dim_x * sizeof(char));
		while (j < e->dim_x)
		{
			e->board[i][j] = '.';
			j++;
		}
		e->board[i][j] = '\0';
		i++;
	}
	e->board[i] = NULL;
}
