# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjang <hjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 15:57:55 by hjang             #+#    #+#              #
#    Updated: 2025/09/26 17:19:15 by hjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = \
		event.c \
		init.c \
		key_event.c \
		key_move.c \
		key_rotate.c \
		main.c \
		map_check.c \
		map_str_check.c \
		map_make.c \
		map_wall_check.c \
		utils.c \
		mouse_rotate_bonus.c		
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_DIR) -lmlx -lXext -lX11 -L$(LIBFT_DIR) -lft -lm

$(MLX_LIB) :
	make -C $(MLX_DIR)

$(LIBFT_LIB) :
	make -C $(LIBFT_DIR)

all : $(NAME)

clean :
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re