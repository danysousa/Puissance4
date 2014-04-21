/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:45:10 by emcoutel          #+#    #+#             */
/*   Updated: 2014/03/09 16:45:07 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ALCU_H
# define ALCU_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include "gnl.h"

# define MIN_Y 6
# define MIN_X 7
# define CHIP_P1 'o'
# define CHIP_P2 'x'

typedef struct	s_env
{
	int			dim_y;
	int			dim_x;
	int			ia;
	int			graph;
	int			player;
	int			best_move[2];
	int			move_y;
	int			move_x;
	int			search_x;
	int			search_y;
	int			n_turn;
	char		chip;
	char		*line;
	char		**board;
}				t_env;

int				ft_strlen(char *s);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putsstr(char **ss);
int				ft_puterror(char *s);
int				ft_getnbr(char *s);
int				check_horiz(t_env *e);
int				check_verti(t_env *e);
int				check_slash(t_env *e);
int				check_bslash(t_env *e);
int				check_board(t_env *e);
int				check_draw(t_env *e);
void			graph(t_env *e, int i, int j);
void			ft_putnbr(int n);
int				define_ty(int tx, t_env *e);
void			ft_init_board(t_env *e);
int				ia_check_board(t_env *e);
void			ia_check_horiz(t_env *e, char disk);
void			ia_check_verti(t_env *e, char disk);
void			ia_check_slash(t_env *e, char disk);
void			ia_check_bslash(t_env *e, char disk);

#endif			/* !ALCU_H */
