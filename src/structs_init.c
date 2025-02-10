/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:31 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/10 18:32:50 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	game->exit_y = get_exit_position(game, 'y');
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

t_img	*initialize_img(mlx_t *mlx, t_game *game)
{
	t_img	*textures;
	
	textures = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!textures)
		error_msg("Memory allocation for a struct has failed.");
	textures = load_wall_texture(mlx, textures, game);
	textures = load_land_texture(mlx, textures, game);
	textures = load_gem_texture(mlx, textures, game);
	textures = load_exit_texture(mlx, textures, game);
	textures = load_player_texture(mlx, textures, game);
	return(textures);
}
