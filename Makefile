# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 17:25:59 by dsousa            #+#    #+#              #
#    Updated: 2014/03/09 16:49:25 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=		-Wall -Wextra -Werror

NAME	=		puissance4

INC		+=		-I includes

HEAD	=		includes/alcu.h includes/gnl.h


SRC_DIR	=		srcs/

FILES	=		check_board.c\
				check_draw.c\
				ft_getnbr.c\
				ft_print.c\
				ft_putnbr.c\
				gnl.c\
				graph.c\
				ia.c\
				ia_board.c\
				init_board.c\
				main.c

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(HEAD)

%.o:			%.c $(HEAD)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re:				fclean all

.PHONY:			all clean fclean re
