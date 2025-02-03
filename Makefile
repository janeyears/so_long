NAME = so_long
CC = cc -Wall -Werror -Wextra -I./inc/
RM = rm -f
SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft
MLX_PATH = ./MLX42

MLX42 = $(MLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = $(SRCS_PATH)/main.c \
		$(SRCS_PATH)/directions.c \
		$(SRCS_PATH)/get_coordinates.c \
		$(SRCS_PATH)/load_textures.c \
		$(SRCS_PATH)/map_checks1.c \
		$(SRCS_PATH)/map_checks2.c \
		$(SRCS_PATH)/map_parsing.c \
		$(SRCS_PATH)/moves.c \
		$(SRCS_PATH)/path_check.c \
		$(SRCS_PATH)/render_map.c \
		$(SRCS_PATH)/structs_init.c \
		$(SRCS_PATH)/utils.c \
		 
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

all: libmlx $(NAME)

libmlx: $(MLX42)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(OBJS) $(MLX42) $(LIBFT) -o $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) -c $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_PATH)

$(MLX42): 
	cd $(MLX_PATH) && cmake -B build && cmake --build build -j4

clean:
	$(RM) -r $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(MLX_PATH)/build

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	
re: fclean all

.PHONY: all clean fclean re libmlx