#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/04/28 20:55:06 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCNAME = 	main.c				\
			environnement.c		\
			ft_cd.c				\
			ft_env.c			\
			ft_exec.c			\
			ft_setenv.c			\
			ft_unsetenv.c		\
			prompt.c			\
			traitement_line.c	\
			caps.c				\
			ft_capture.c		\

SRCPATH = ./srcs/

SRC = $(addprefix $(SRCPATH), $(SRCNAME))

OBJNAME = $(SRCNAME:.c=.o)

OBJPATH = ./objs/

OBJ = $(addprefix $(OBJPATH), $(OBJNAME))

NAME = Minishell

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	create_obj	$(OBJ)
	make -C libft/
	gcc $(FLAG) $(OBJ) -I ./headers/ -lncurses libft/libft.a -o $(NAME)

$(OBJPATH)%.o:	$(SRCPATH)%.c
	gcc $(FLAGS) -I ./headers/ -c $< -o $@

create_obj :
	mkdir -p $(OBJ_PATH)

clean:
	/bin/rm -rf $(OBJ_PATH)
	make -C ./libft/ clean

fclean: clean
	/bin /rm $(NAME)
	make -C ./libft/ fclean

re:	fclean  all

