#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/04/08 12:07:31 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
HEADER = libft.h
SRC_PATH=./
OBJ_PATH=./
SRC =  ft_isalnum.c ft_isprint.c ft_lstcount.c ft_lstmap.c ft_memchr.c ft_memmove.c ft_putendl.c ft_putstr.c ft_strclr.c ft_strdup.c ft_strjoin.c ft_strmapi.c ft_strnequ.c ft_strsplit.c ft_swap.c ft_toupper.c ft_isalpha.c ft_itoa.c ft_lstdel.c ft_lstnew.c ft_memcmp.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strcmp.c ft_strequ.c ft_strlcat.c ft_strncat.c ft_strnew.c ft_strstr.c ft_tabcount.c ft_atoi.c ft_isascii.c ft_lstaddend.c ft_lstdelone.c ft_memalloc.c ft_memcpy.c ft_putchar.c ft_putnbr.c ft_strcat.c ft_strcpy.c ft_striter.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strsub.c ft_tabtri.c ft_bzero.c ft_isdigit.c ft_lstadd.c ft_lstiter.c ft_memccpy.c ft_memdel.c ft_putchar_fd.c ft_putnbr_fd.c ft_strchr.c ft_strdel.c ft_striteri.c ft_strmap.c ft_strncpy.c ft_strrchr.c ft_strtrim.c ft_tolower.c ft_replace_first.c ft_itoa_base.c ft_split_copy.c ft_str_char_cmp.c get_next_line.c ft_strpushback.c ft_free_double_str.c ft_get_size_double_str.c ft_insert_double_str.c ft_replace_char.c ft_delete_double_str.c

OBJ = $(SRC:.c=.o )

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
