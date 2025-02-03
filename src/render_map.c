/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:34:33 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/03 13:39:00 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	image_select(t_game *data, size_t y, size_t x)
{
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("image_to_window has failed");
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->exit,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("image_to_window has failed");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->gem,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("image_to_window has failed");
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->player,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("image_to_window has failed");
}

void	fill_land(t_game *data)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->img->land,
					x * PIXELS, y * PIXELS) < 0)
				error_msg("image_to_window has failed");
			x++;
		}
		y++;
	}
}

void	render_map(t_game *data)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			image_select(data, y, x);
			x++;
		}
		y++;
	}
	if (data->img->player->instances->z < data->img->exit->instances->z)
		mlx_set_instance_depth(data->img->exit->instances, data->img->player->instances->z - 1);
}