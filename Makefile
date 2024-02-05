# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujin <sujin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:37:35 by yerilee           #+#    #+#              #
#    Updated: 2024/02/06 04:44:45 by sujin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

GNL = parsing/get_next_line/get_next_line.c parsing/get_next_line/get_next_line_utils.c

SRCS = main.c \
	execution/dda.c execution/draw.c execution/executing.c execution/key.c execution/move.c execution/utils.c \
	parsing/check_dup.c parsing/check_map1.c parsing/check_map2.c parsing/check.c parsing/ewsn.c \
	parsing/ft_split.c parsing/init1.c parsing/init2.c parsing/parsing.c parsing/read_map.c \
	parsing/rgb.c parsing/utils.c libft/ft_atoi.c libft/ft_strcpy.c libft/ft_strncmp.c
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