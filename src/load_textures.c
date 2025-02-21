/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:36:04 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/21 14:50:54 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_wall_texture(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./textures/wall.png");
	if (!wall)
		error_free("Couldn't upload texture", game);
	game->img->wall = mlx_texture_to_image(mlx, wall);
	if (!game->img->wall)
	{
		mlx_delete_texture(wall);
		error_free("Couldn't convert texture to image", game);
	}
	mlx_delete_texture(wall);
}

void	load_land_texture(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*land;

	land = mlx_load_png("./textures/land.png");
	if (!land)
		error_free("Couldn't upload texture", game);
	game->img->land = mlx_texture_to_image(mlx, land);
	if (!game->img->land)
	{
		mlx_delete_texture(land);
		error_free("Couldn't convert texture to image", game);
	}
	mlx_delete_texture(land);
}

void	load_gem_texture(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*gem;

	gem = mlx_load_png("./textures/gem.png");
	if (!gem)
		error_free("Couldn't upload texture", game);
	game->img->gem = mlx_texture_to_image(mlx, gem);
	if (!game->img->gem)
	{
		mlx_delete_texture(gem);
		error_free("Couldn't convert texture to image", game);
	}
	mlx_delete_texture(gem);
}

void	load_exit_texture(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*exit;

	(void)mlx;
	exit = mlx_load_png("./textures/exit.png");
	if (!exit)
		error_free("Couldn't upload texture", game);
	game->img->exit = mlx_texture_to_image(mlx, exit);
	if (!game->img->exit)
	{
		mlx_delete_texture(exit);
		error_free("Couldn't convert texture to image", game);
	}
	mlx_delete_texture(exit);
}

void	load_player_texture(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./textures/char.png");
	if (!player)
		error_free("Couldn't upload texture", game);
	game->img->player = mlx_texture_to_image(mlx, player);
	if (!game->img->player)
	{
		mlx_delete_texture(player);
		error_free("Couldn't convert texture to image", game);
	}
	mlx_delete_texture(player);
}
