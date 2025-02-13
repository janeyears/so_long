/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:34:33 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:12 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	image_select(t_game *game, size_t y, size_t x)
{
	if (game->map[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_free("image_to_window has failed", game);
	if (game->map[y][x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img->exit,
				x * PIXELS, y * PIXELS) < 0)
			error_free("image_to_window has failed", game);
	if (game->map[y][x] == 'C')
		if (mlx_image_to_window(game->mlx, game->img->gem,
				x * PIXELS, y * PIXELS) < 0)
			error_free("image_to_window has failed", game);
	if (game->map[y][x] == 'P')
		if (mlx_image_to_window(game->mlx, game->img->player,
				x * PIXELS, y * PIXELS) < 0)
			error_free("image_to_window has failed", game);
}

void	fill_land(t_game *game)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->land,
					x * PIXELS, y * PIXELS) < 0)
				error_free("image_to_window has failed", game);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	size_t		x;
	size_t		y;
	int32_t		exit_depth;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			image_select(game, y, x);
			x++;
		}
		y++;
	}
	if (game->img->player->instances->z < game->img->exit->instances->z)
	{
		exit_depth = game->img->player->instances->z - 1;
		mlx_set_instance_depth(game->img->exit->instances, exit_depth);
	}
}
