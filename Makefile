NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -ldl -lglfw -pthread -lm
LIBFT = ./libft/libft.a
LIBMLX42 = ./MLX42/build/libmlx42.a
INCLUDES = -I./inc -I./MLX42/include -I.libft/
MLX42_PATH = ./MLX42
SRC_PATH = src/
OBJ_PATH = obj/

SRCS = $(SRC_PATH)/main.c \
		$(SRC_PATH)/hook_directions.c \
		$(SRC_PATH)/load_textures.c \
		$(SRC_PATH)/map_checks.c \
		$(SRC_PATH)/wall_check.c \
		$(SRC_PATH)/map_parsing.c \
		$(SRC_PATH)/move_handling.c \
		$(SRC_PATH)/check_map_path.c \
		$(SRC_PATH)/render_map_image.c \
		$(SRC_PATH)/structs_init.c \
		$(SRC_PATH)/utils.c \
		$(SRC_PATH)/error_handling.c \

SRC	= $(addprefix $(SRC_PATH), $(SRCS))
OBJ = $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

all:	$(NAME) 

$(NAME): check_MLX42_PATH $(OBJ) $(LIBFT) $(LIBMLX42) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX42) $(MLX42FLAGS)

$(LIBFT):
	@$(MAKE) -C ./libft

$(LIBMLX42):
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4

check_MLX42_PATH:
	@if ! [ -d "$(MLX42_PATH)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_PATH); \
	fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean: 
	@$(MAKE) -C ./libft clean 
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -rf ./MLX42/build
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re check_MLX42_PATH
