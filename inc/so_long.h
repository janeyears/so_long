/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:48:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/14 15:21:24 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define TILE_SIZE 32

typedef struct s_img
{
	mlx_image_t			*wall;
	mlx_image_t			*land;
	mlx_image_t			*gem;
	mlx_image_t			*player;
	mlx_image_t			*exit;
}	t_img;

typedef struct s_game
{
	char			**map;
	size_t			width;
	size_t			height;
	size_t			gems;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			moves;
	size_t			exit_x;
	size_t			exit_y;
	t_img			*img;
	mlx_t			*mlx;
}	t_game;

// Map checking

void	validate_map_elements(char *map);
void	check_invalid_symbols(int i, char *map);
void	check_map_ber(char *file);
void	check_map_rectangle(char **grid);
void	check_empty_file_lines(char *map);
void	check_walls(t_game *game);

// Texture loadings

void	load_wall_texture(mlx_t *mlx, t_game *game);
void	load_land_texture(mlx_t *mlx, t_game *game);
void	load_gem_texture(mlx_t *mlx, t_game *game);
void	load_exit_texture(mlx_t *mlx, t_game *game);
void	load_player_texture(mlx_t *mlx, t_game *game);

// Struct initializations

t_game	*initialize_map(char *map);
void	initialize_img(mlx_t *mlx, t_game *game);

// Coordinates

size_t	get_player_position(t_game *game, char c);
size_t	get_exit_position(t_game *game, char c);

// Map parsing, rendering and path checking

size_t	count_rows(char **grid);
size_t	count_gems(t_game *game);
char	*read_map(char *map);
void	fill_land(t_game *data);
void	render_map(t_game *data);
void	free_grid(char **grid, size_t height);
void	temp_map(t_game *game);

// Directions and moves

void	move_hook(mlx_key_data_t keydata, void *data);
t_game	*moving_up(t_game *game);
t_game	*moving_down(t_game *game);
t_game	*moving_right(t_game *game);
t_game	*moving_left(t_game *game);

// Utils

void	error_free(char *msg, t_game *game);
void	check_end_game(t_game *game);
void	free_game(t_game *game);
void	error_msg(char *msg);
void	error_msg_exit(char *msg);
void	free_map_arr(char **map_arr);

#endif
