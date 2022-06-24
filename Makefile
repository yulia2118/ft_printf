# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/28 19:24:06 by fdarrin           #+#    #+#              #
#    Updated: 2020/07/30 23:47:01 by fdarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

NAME = libftprintf.a

SRC = ft_printf.c	ft_flags.c  ft_printf_utils.c	ft_percent_type.c	ft_char_type.c\
	ft_string_type.c ft_pointer_type.c	ft_int_type.c  ft_unint_type.c	ft_xx_type.c

SRC_DIR = ./src/

SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)

OBJ_DIR = ./obj/

OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	cd libft && make
	cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)
	test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@ -I. -I./libft/

clean:
	make clean -C ./libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
