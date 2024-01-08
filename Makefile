NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror


MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c\

OBJS = $(SRCS:.c=.o)

al:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re