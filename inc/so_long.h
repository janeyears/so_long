/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:48:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:18 by ekashirs         ###   ########.fr       */
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

// Utils

void	error_msg(char *msg);
void	check_end_game(t_game *game);

#endif
