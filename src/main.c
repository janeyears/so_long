/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:23:05 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/18 14:44:48 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		error_msg("Invalid number of arguments.");
		exit(1);
	}
	check_map_ber(av[1]);
	game = initialize_map(av[1]);
	if (game->width * TILE_SIZE > 3840 || game->height * TILE_SIZE > 2160)
		error_free("Game width or height is too big", game);
	game->mlx = mlx_init(game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		error_free("Couldn't create game with mlx library", game);
	initialize_img(game->mlx, game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fill_land(game);
	render_map(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	free(game);
	return (0);
}
