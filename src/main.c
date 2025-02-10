/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:23:05 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/05 11:37:38 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main (int argc, char **argv)
{
	t_game	*game;
	t_img	*textures;

	if (argc != 2)
		error_msg("Invalid number of arguments.");
	check_map_ber(argv[1]);
	game = initialize_map_data(argv[1]);
	game->mlx  =mlx_init(game->width  * PIXELS, game->height * PIXELS, "so_long", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	textures = initialize_img(game->mlx);
	game->img = textures;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fill_land(game);
	render_map(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (0);
	
}