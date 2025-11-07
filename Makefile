# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 15:57:55 by hjang             #+#    #+#              #
#    Updated: 2025/11/05 17:18:50 by byeolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c \
		event_window/event.c \
		event_window/event_make_screen_line.c\
		event_window/event_make_screen_line_per.c\
		event_window/event_make_screen.c\
		event_window/event_make_screen2.c\
		event_window/init_map.c \
		event_window/init_sl.c \
		event_window/init_sl_check_tex.c \
		event_window/init_sl_load_tex.c \
		event_window/event_close.c \
		event_keys/key_event.c \
		event_keys/key_move.c \
		event_keys/key_rotate.c \
		event_map/map_check.c \
		event_map/map_check_external.c \
		event_map/map_check_setting.c \
		event_map/map_check_setting_texture.c \
		event_map/map_check_setting_color.c \
		event_map/map_check_internal.c \
		event_map/map_str_check.c \
		event_map/map_str_check_validation.c \
		event_map/map_str_check_setting.c\
		event_map/map_str_check_len.c\
		event_map/map_make.c \
		event_map/map_make_init.c \
		event_map/map_wall_check.c \
		event_minimap/event_minimap.c\
		event_minimap/draw_minimap_map.c\
		event_minimap/draw_minimap_cha.c\
		event_minimap/draw_minimap_fov.c\
		utils.c	\
		event_mouse/mouse_rotate_bonus.c \
		event_mouse/mouse_rotate_player_bonus.c
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