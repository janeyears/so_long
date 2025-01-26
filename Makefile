NAME = so_long
CC = cc -Wall -Werror -Wextra -I./inc/
RM = rm -f

SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft
MLX_PATH = ./mlx42
MLX_FLAGS = -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit

MLX42 = $(MLX_PATH)/libmlx42.a
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = .src/main.c \
		.src/dirictions.c \
		.src/get_coordinates.c \
		.src/load_textures.c \
		.src/map_checks1.c \
		.src/map_checks2.c \
		.src/moves.c \
		.src/path_check.c \
		.src/render_map.c \
		.src/struct_init.c \
		.src/utils.c \
		 
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(MLX42) $(MLX_FLAGS)
	
$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX42):
	@$(MAKE) -C $(MLX_PATH)

clean:
	$(RM) -r $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -s -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -s -C $(MLX_PATH) clean
	
re: fclean all

.PHONY: all clean fclean re
