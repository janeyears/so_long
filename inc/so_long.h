/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:48:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/24 12:44:04 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define PIXELS 32

typedef struct s_img {
	mlx_image_t			*wall;
	mlx_image_t			*land;
	mlx_image_t			*gem;
	mlx_image_t			*player;
	mlx_image_t			*exit;
	mlx_image_t			*moves_nbr;
}	t_img;

typedef struct s_game {
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			gems;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			moves;
	size_t			exit_x;
	size_t			exit_y;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	t_img			*img;
	mlx_t			*mlx;
}	t_game;

// Map checking

void	check_invalid_symbols(int i);
void	check_map_content(char *map);
void	check_map_ber(char *file);
void	check_map_rectangle(char **grid);
void	check_empty(char *map);
void	check_empty_lines(char *map);
void	check_walls(t_game *game);

// Texture loadings

t_img	*load_wall_texture(mlx_t *mlx, t_img *img);
t_img	*load_land_texture(mlx_t *mlx, t_img *img);
t_img	*load_gem_texture(mlx_t *mlx, t_img *img);
t_img	*load_exit_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);

// Struct initializations

t_game	*initialize_game(char **grid);
t_game	*initialize_map_data(char *map);
t_img	*initialize_img(mlx_t *mlx);

// Coordinates

size_t	get_player_position(t_game *game, char c);
size_t	get_exit_position(t_game *game, char c);

// Map parsing, rendering and path checking

size_t	count_rows(char **grid);
size_t	count_gems(t_game *game);
char	*read_map(char *map);
void	image_select(t_game *data, size_t y, size_t x);
void	fill_land(t_game *data);
void	render_map(t_game *data);
void	free_grid(char **grid, size_t height);
int	check_path(t_game *temp, size_t y, size_t x);
void	temp_map(t_game *game);

// Directions and moves

void	load_player(t_game *game, char dir);
void	select_move(t_game *game, char line, char dir);
void	move_player(t_game *game, char line, char dir);
void	move_hook(mlx_key_data_t keydata, void *data);
void	remove_gem(t_game *game, int y, int x);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);

// Utils

void	error_msg(char *msg);
void	check_end_game(t_game *game);

#endif
