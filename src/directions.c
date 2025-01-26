/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:23:11 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/24 12:34:50 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_player(t_game *game, char dir)
{
	if (dir == 'u')
		mlx_draw_texture(game->img->player, game->player_up, 0, 0);
	if (dir == 'd')
		mlx_draw_texture(game->img->player, game->player_down, 0, 0);
	if (dir == 'r')
		mlx_draw_texture(game->img->player, game->player_right, 0, 0);
	if (dir == 'l')
		mlx_draw_texture(game->img->player, game->player_left, 0, 0);
}

void	select_move(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'r')
			move_right(game);
		else
			move_left(game);
	}
}

void	move_player(t_game *game, char line, char dir)
{
	select_move(game, line, dir);
	load_player(game, dir);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'r');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'l');
}