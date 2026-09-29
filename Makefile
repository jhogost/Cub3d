# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 17:35:11 by jbayet            #+#    #+#              #
#    Updated: 2026/06/15 11:42:41 by jbayet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
BONUS_NAME		= cub3D_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address

MLX_DIR			= minilibx-linux
MLX_LIB			= $(MLX_DIR)/libmlx.a

INCLUDES		= -I mandatory -I bonus -I $(MLX_DIR)

# ========================= MANDATORY ========================= #

SRC_MANDATORY	=	mandatory/srcs/cub3D.c \
					mandatory/srcs/init.c \
					mandatory/srcs/init_base.c \
					mandatory/srcs/init_map.c \
					mandatory/srcs/parsing.c \
					mandatory/srcs/parsing_map.c \
					mandatory/srcs/parsing_elem.c \
					mandatory/srcs/check.c \
					mandatory/srcs/free.c \
					mandatory/srcs/free_textures.c \
					mandatory/srcs/engine/render.c \
					mandatory/srcs/engine/raycasting.c \
					mandatory/srcs/engine/textures.c \
					mandatory/srcs/engine/player_controls.c \
					mandatory/srcs/engine/walls.c \
					mandatory/utils/utils_game.c \
					mandatory/utils/utils_graphic.c \
					mandatory/utils/utils.c \
					mandatory/utils/utils2.c \
					mandatory/utils/utils3.c \
					mandatory/utils/get_next_line.c

OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)

# =========================== BONUS =========================== #

SRC_BONUS		=	bonus/srcs/cub3D.c \
					bonus/srcs/win_loose.c \
					bonus/srcs/init.c \
					bonus/srcs/init_stage.c \
					bonus/srcs/init_base.c \
					bonus/srcs/init_textures.c \
					bonus/srcs/init_textures_2.c \
					bonus/srcs/init_textu_data.c \
					bonus/srcs/init_map.c \
					bonus/srcs/init_sprite.c \
					bonus/srcs/parsing.c \
					bonus/srcs/parsing_line.c \
					bonus/srcs/parsing_map.c \
					bonus/srcs/parsing_elem.c \
					bonus/srcs/check.c \
					bonus/srcs/free.c \
					bonus/srcs/free_stage.c \
					bonus/srcs/free_textures.c \
					bonus/srcs/free_textures_2.c \
					bonus/srcs/engine/render.c \
					bonus/srcs/engine/raycasting.c \
					bonus/srcs/engine/raycasting_extra.c \
					bonus/srcs/engine/textures.c \
					bonus/srcs/engine/player_controls.c \
					bonus/srcs/engine/player_action.c \
					bonus/srcs/engine/target_action.c \
					bonus/srcs/engine/walls.c \
					bonus/srcs/engine/hud.c \
					bonus/srcs/engine/manage_sprite.c \
					bonus/srcs/engine/sprite.c \
					bonus/srcs/engine/mouse.c \
					bonus/srcs/engine/doors.c \
					bonus/utils/utils_game.c \
					bonus/utils/utils_game1.c \
					bonus/utils/utils_game2.c \
					bonus/utils/utils_graphic.c \
					bonus/utils/utils.c \
					bonus/utils/utils2.c \
					bonus/utils/utils3.c \
					bonus/utils/get_next_line.c

OBJ_BONUS		= $(SRC_BONUS:.c=.o)

# ============================ LIBS =========================== #

LIBS			= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# ============================ RULES ========================== #

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MLX_LIB) $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(MLX_LIB) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ_MANDATORY)
	rm -f $(OBJ_BONUS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
