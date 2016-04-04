#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/04/04 16:00:18 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Minishell
HEADER = libft/libft.h headers/minishell.h
SRC_PATH=srcs/
OBJ_PATH=objs/
LIBS= libft/libft.a
SRCCAT= $(addprefix $(SRC_PATH), $(SRC))
OBJ= $(SRCCAT:.c=.o)
SRC =	main.c				\
		prompt.c			\
		environnement.c		\
		traitement_line.c	\
		ft_cd.c				\

all : lib $(NAME)

$(NAME) : $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) $(LIBS) -g -o $(NAME)

lib :
	make -C libft/

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -g -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re : fclean all
