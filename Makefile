# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 16:38:37 by muhcelik          #+#    #+#              #
#    Updated: 2023/05/06 16:43:55 by muhcelik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = map_info.c map_check.c utils.c utils2.c main.c valid_path_check.c mlx_controler.c \
		mlx_controler2.c ./SRC/get_next_line/libftgnl.a
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a
GNL_SRCS = ./SRC/get_next_line/libftgnl.a
GNL_OBJS = $(GNL_SRCS:.c=.o)
MLX = ./SRC/mlx/libmlx.a
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit -L./SRC/mlx -lmlx

CC=gcc

all: $(MLX) $(NAME) $(OBJS) $(GNL_OBJS)

$(NAME): $(MLX) $(OBJS) $(GNL_OBJS)
		gcc $(CFLAGS) $(LFLAGS) $(OBJS) $(GNL_OBJS) -o $(NAME)
$(MLX):
	$(MAKE) -C ./SRC/mlx
$(GNL_OBJS):
	@make -C ./SRC/get_next_line

clean:
	make clean -C ./SRC/get_next_line
	@rm -rf $(OBJS)
	make clean -C ./SRC/mlx

fclean: clean
	@rm -rf ./SRC/mlx/libmlx.a
	@rm -rf ./SRC/get_next_line/libftgnl.a
	@rm -rf $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
