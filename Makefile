# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebertin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 13:32:04 by ebertin           #+#    #+#              #
#    Updated: 2018/01/05 17:06:57 by ebertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re, re_bis

NAME = fractol

CC = clang
CC_FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
INC_PATH = ./
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fdf.h

SRC_NAME = main.c \
	   key_funct.c \
	   move.c \
	   palette.c \
		 mouse_funct.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx -lXext -lX11 -g


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)
clean_o:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)

re_bis: clean_o $(NAME)

re: fclean all
