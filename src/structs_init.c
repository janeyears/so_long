/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:31 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 14:50:51 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_game	*initialize_game(char **map)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		free_map_arr(map);
		error_msg_exit("Memory allocation for a struct has failed.");
		return (NULL);
	}
	game->map = map;
	game->width = ft_strlen(map[0]);
	game->height = count_rows(map);
	game->gems = count_gems(game);
	game->moves = 0;
	game->player_x = get_player_position(game, 'x');
	game->player_y = get_player_position(game, 'y');
	game->exit_x = get_exit_position(game, 'x');
	game->exit_y = get_exit_position(game, 'y');
	return (game);
}

t_game	*initialize_map_data(char *map)
{
	char	*map_str;
	char	**map_arr;
	t_game	*data;

	map_str = read_map(map);
	if (!map_str)
		error_msg_exit("Reading map has failed");
	check_empty_file_lines(map_str);
	validate_map_elements(map_str);
	map_arr = ft_split(map_str, '\n');
	if (!map_arr)
	{
		free(map_str);
		free_map_arr(map_arr);
		error_msg_exit("Creating 2D map array has failed");
	}
	free(map_str);
	check_map_rectangle(map_arr);
	data = initialize_game(map_arr);
	check_walls(data);
	temp_map(data);
	return (data);
}

void	initialize_img(mlx_t *mlx, t_game *game)
{
	game->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!game->img)
		error_free("Memory allocation for a struct has failed.", game);
	load_wall_texture(mlx, game);
	load_land_texture(mlx, game);
	load_gem_texture(mlx, game);
	load_exit_texture(mlx, game);
	load_player_texture(mlx, game);
}
