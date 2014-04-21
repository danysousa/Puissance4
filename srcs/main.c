/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:46:52 by dsousa            #+#    #+#             */
/*   Updated: 2014/03/09 18:11:00 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			init_env(t_env *e, int ac, char **av)
{
	if (ac < 3)
		return (ft_puterror("Usage: ./puissance4 <Y> <X> [<IA> <GRAPH>]\n"));
	e->dim_y = ft_getnbr(av[1]);
	e->dim_x = ft_getnbr(av[2]);
	e->ia = 1;
	if (av[3])
		e->ia = ft_getnbr(av[3]);
	e->ia = (e->ia > 0 ? 1 : 0);
	if (av[4] && av[4][0] == '0')
		e->graph = 0;
	else
		e->graph = 1;
	e->graph = (e->graph > 0 ? 1 : 0);
	e->player = 1;
	e->move_y = 0;
	e->move_x = 0;
	e->n_turn = 1;
	if (e->dim_y < MIN_Y)
		return (ft_puterror("Error: Y too small\n"));
	if (e->dim_x < MIN_X)
		return (ft_puterror("Error: X too small\n"));
	ft_init_board(e);
	return (0);
}

void		print_game(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->dim_y)
	{
		j = 0;
		while (j < e->dim_x)
		{
			graph(e, i, j);
			ft_putstr("  ");
			j++;
		}
		i += ft_putchar('\n');
	}
	i = 1;
	while (i <= e->dim_x)
	{
		ft_putnbr(i);
		if (i < 100)
			ft_putchar(' ');
		if (i < 10)
			ft_putchar(' ');
		i++;
	}
}

void		set_game(t_env *e)
{
	ft_putstr("Player 1: HUMAN - Play ");
	ft_putchar(CHIP_P1);
	if (e->ia == 1)
		ft_putstr("\nPlayer 2: IA - Play ");
	if (e->ia == 0)
		ft_putstr("\nPlayer 2: HUMAN - Play ");
	ft_putchar(CHIP_P2);
	ft_putstr("\n\n");
	srand(time(NULL));
	e->player = 1 + rand() % 2;
}

void		play(t_env *e)
{
	e->move_y = e->dim_y;
	if (e->player == 1 || !e->ia)
	{
		get_next_line(0, &e->line);
		e->move_x = ft_getnbr(e->line) - 1;
		while (e->move_x < 0 || e->move_x > e->dim_x
				|| e->board[0][e->move_x] != '.')
		{
			ft_putstr("> Move forbidden, please retry\n");
			get_next_line(0, &e->line);
			e->move_x = ft_getnbr(e->line) - 1;
		}
		free(e->line);
	}
	else if (e->ia)
		e->move_x = ia_check_board(e);
	while (e->move_y--)
	{
		if (e->board[e->move_y][e->move_x] == '.')
		{
			e->board[e->move_y][e->move_x] = e->chip;
			break ;
		}
	}
}

int			main(int ac, char **av)
{
	t_env	e;

	if (init_env(&e, ac, av) == -1)
		return (-1);
	set_game(&e);
	while (!check_board(&e) && !check_draw(&e))
	{
		e.chip = (e.player == 1 ? CHIP_P1 : CHIP_P2);
		print_game(&e);
		if (e.player == 1)
			ft_putstr("\n\n>\033[31m Player 1\033[0m, your turn\n");
		if (e.player == 2)
			ft_putstr("\n\n>\033[33m Player 2\033[0m, your turn\n");
		play(&e);
		e.player = (e.player == 1 ? 2 : 1);
	}
	print_game(&e);
	if (e.player == 3)
		ft_putstr("\n\nDraw !\n");
	if (e.player == 2)
		ft_putstr("\n\n\033[31mPlayer 1 win !\033[0m\n");
	if (e.player == 1)
		ft_putstr("\n\n\033[33mPlayer 2 win !\033[0m\n");
	return (0);
}
