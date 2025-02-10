NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -ldl -lglfw -pthread -lm 
LIBFT = ./libft/libft.a
LIBMLX42 = ./MLX42/build/libmlx42.a
INCLUDES = -I./include -I./MLX42/include
MLX42_DIR = ./MLX42
SRC_DIR = src/
OBJ_DIR = obj/

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR))/directions.c \
		$(SRC_DIR))/get_coordinates.c \
		$(SRC_DIR)/load_textures.c \
		$(SRC_DIR)/map_checks1.c \
		$(SRC_DIR))/map_checks2.c \
		$(SRC_DIR)/map_parsing.c \
		$(SRC_DIR)/moves.c \
		$(SRC_DIR)/path_check.c \
		$(SRC_DIR)/render_map.c \
		$(SRC_DIR)/structs_init.c \
		$(SRC_DIR)/utils.c \

SRC	= $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all:	check_MLX42_dir	$(NAME) 

$(NAME): $(LIBFT) libmlx $(LIBMLX42) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX42) $(MLX42FLAGS)

$(LIBFT):
	@$(MAKE) -C ./libft

libmlx:
	@cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4

check_MLX42_dir:
	@if ! [ -d "$(MLX42_DIR)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
