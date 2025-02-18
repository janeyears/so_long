/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:23:11 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/18 16:44:24 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	select_move_direction(t_game *game, char dir)
{
	if (dir == 'u')
		moving_up(game);
	if (dir == 'd')
		moving_down(game);
	if (dir == 'r')
		moving_right(game);
	if (dir == 'l')
		moving_left(game);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		select_move_direction(game, 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		select_move_direction(game, 'l');
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		select_move_direction(game, 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		select_move_direction(game, 'r');
}
