# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:37:35 by yerilee           #+#    #+#              #
#    Updated: 2024/01/18 15:01:08 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
		execution/executing.c execution/init.c execution/key.c execution/move.c execution/utils.c \

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re