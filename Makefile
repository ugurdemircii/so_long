NAME = so_long
SRCS = map_check.c map_check2.c so_long.c  dfs.c \
    	key_events.c render.c initialize.c \
		free_game.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
LDFLAGS =  -Lminilibx-linux -lmlx -Llibft -lft -lX11 -lXext -lm

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	 
$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C  libft fclean
	make -C  minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re