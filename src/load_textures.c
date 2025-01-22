/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:36:04 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/22 15:53:49 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_img	*load_wall_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*wall;
	wall = mlx_load_png("./textures/wall.png");
	if (!wall)
		error_msg("Couldn't upload texture");
	img->wall = mlx_texture_to_image(mlx, wall);
	if(!img->wall)
		error_msg("Couldn't convert texture to image");
	mlx_delete_texture(wall);
	return(img);
}

t_img	*load_land_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*land;
	land = mlx_load_png("./textures/land.png");
	if (!land)
		error_msg("Couldn't upload texture");
	img->land = mlx_texture_to_image(mlx, land);
	if(!img->land)
		error_msg("Couldn't convert texture to image");
	mlx_delete_texture(land);
	return(img);
}

t_img	*load_gem_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*gem;
	gem = mlx_load_png("./textures/land.png");
	if (!gem)
		error_msg("Couldn't upload texture");
	img->gem = mlx_texture_to_image(mlx, gem);
	if(!img->gem)
		error_msg("Couldn't convert texture to image");
	mlx_delete_texture(gem);
	return(img);
}

t_img	*load_exit_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;
	exit = mlx_load_png("./textures/exit.png");
	if (!exit)
		error_msg("Couldn't upload texture");
	img->exit = mlx_texture_to_image(mlx, exit);
	if(!img->exit)
		error_msg("Couldn't convert texture to image");
	mlx_delete_texture(exit);
	return(img);
}
t_img	*load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;
	player = mlx_load_png("./textures/char.png");
	if (!player)
		error_msg("Couldn't upload texture");
	img->player = mlx_texture_to_image(mlx, player);
	if(!img->player)
		error_msg("Couldn't convert texture to image");
	mlx_delete_texture(player);
	return(img);
}