# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 18:23:16 by xuwang            #+#    #+#              #
#    Updated: 2021/07/26 19:30:46 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc 
CFLAGS 	= -Wall -Wextra -Werror #-g3 -fsanitize=address
MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
IFLAGS = -I. -I./libft -I./mlx
LFLAGS = -L./libft -lft
BFLAGS = 0

MLX_DIR = ./mlx
MLX = libmlx.dylib

SRC	:= srcs/parser/check.c \
		srcs/parser/check_map.c \
		srcs/utils/exit.c \
		srcs/main.c \
		srcs/events/even_key.c \
		srcs/image/imag.c \
		srcs/image/tex.c \
		srcs/events/even_bonus.c 
		
OBJ	:= $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ -D BONUS=$(BFLAGS)


ifeq ($(shell uname), Linux)
$(NAME): IFLAGS = -I. -I./libft -I./mlx_linux
$(NAME): MFLAGS	= -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a
endif
$(NAME): $(OBJ)
	$(MAKE) -C ./$(MLX_DIR)
	cp ./$(MLX_DIR)/$(MLX) .
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@ 

all: $(NAME)

bonus: BFLAGS = 1
bonus: $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

ifeq ($(shell uname), Linux)
fclean: MLX_DIR = ./mlx_linux
fclean: MLX = libmlx.a
endif
fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ./$(MLX_DIR) clean
	rm -rf $(MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re