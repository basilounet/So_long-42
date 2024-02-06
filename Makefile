SRC = map_handler_utils.c \
		map_handler.c \
		music.c \
		errors.c \
		unleak_structs.c \
		unleak.c \
		struct_innit.c \
		textures_name_terrain.c \
		ground.c \
		fonts.c \
		collectibles.c \
		walls.c \
		exit.c \
		rule_tile.c \
		wall_rules.c \
		player_textures.c \
		enemies_movment.c \
		enemies_textures.c \
		player_movment.c \
		entity_animation.c \
		so_long.c 
OBJS = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIBS) #-fsanitize=address
MLX_INCLUDE_FLAGS = -I/usr/include -Imlx_linux -O3 -c
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/build/libmlx42.a
LIBMLX	:= ./MLX42
LIBS	:= -L$(LIBMLX)/build -lmlx42 -ldl -lglfw -pthread -lm -Llibft -lft

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build --no-print-directory -j4

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

%.o : %.c
	@$(CC) $(CFLAGS) $(MLX_INCLUDE_FLAGS) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory -j4

clean :
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C libft clean --no-print-directory

fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft fclean --no-print-directory
	@echo "Files cleaned"

first : 
	@git clone https://github.com/codam-coding-college/MLX42.git

cleanall : fclean
	@rm -rf MLX42

re : fclean all

.PHONY : all clean fclean re libmlx first cleanall