# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:37:35 by yerilee           #+#    #+#              #
#    Updated: 2024/01/26 21:26:12 by spark2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

GNL = parsing/get_next_line/get_next_line.c parsing/get_next_line/get_next_line_utils.c

SRCS = main.c \
	execution/executing.c execution/init.c execution/key.c execution/move.c execution/utils.c \
	parsing/check.c parsing/ft_split.c parsing/init.c parsing/parsing.c parsing/read_map.c parsing/rgb.c \
	parsing/utils.c \
	libft/ft_atoi.c libft/ft_strncmp.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

all: $(NAME)

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