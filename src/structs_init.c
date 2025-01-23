/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:31 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/23 11:32:49 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_player_moves_textures(t_game *game)
{

	game->player_up = mlx_load_png("./textures/char_up.png");
	if (!game->player_up)
		error_msg("Couldn't upload player's png");
	game->player_down = mlx_load_png("./textures/char_down.png");
	if (!game->player_down)
		error_msg("Couldn't upload player's png");
	game->player_right = mlx_load_png("./textures/char_right.png");
	if (!game->player_right)
		error_msg("Couldn't upload player's png");
	game->player_left = mlx_load_png("./textures/char_left.png");
	if (!game->player_left)
		error_msg("Couldn't upload player's png");
}

t_game	*initialize_game(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_msg("Memory allocation for a struct has failed.");
	game->grid = grid;
	game->width = ft_strlen(grid[0]);
	game->height = count_rows(grid);
	game->gems = count_gems(game);
	game->moves = 0;
	game->player_x = get_player_position(game, 'x');
	game->player_y = get_player_position(game, 'y');
	game->exit_x = get_exit_position(game, 'x');
	game->exit_x = get_exit_position(game, 'y');
	load_player_moves_textures(game);
	return(game);
}

t_game	*initialize_map_data(char *map)
{
	char	*map_str;
	char	**map_arr;
	t_game	*data;

	map_str = read_map(map);
	check_empty(map_str);
	check_empty_lines(map_str);
	check_map_content(map_str);
	map_arr = ft_split(map_str, '\n');
	check_map_rectangle(map_arr);
	data = initialize_game(map_arr);
	check_walls(data);
	temp_map(data);
	free(map_str);
	return (data);
}

t_img	*initialize_img(mlx_t *mlx)
{
	t_img	*textures;
	
	textures = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!textures)
		error_msg("Memory allocation for a struct has failed.");
	textures = load_wall_texture(mlx, textures);
	textures = load_land_texture(mlx, textures);
	textures = load_gem_texture(mlx, textures);
	textures = load_player_texture(mlx, textures);
	textures = load_exit_texture(mlx, textures);
	return(textures);
}
