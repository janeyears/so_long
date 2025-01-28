/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:34:44 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/28 17:56:35 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->grid[game->player_y - 1][game->player_x] != '1')
	{
		if (game->grid[game->player_y - 1][game->player_x] == 'C')
		{
			mlx_delete_image(game->mlx, game->img->gem);
			game->grid[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d\n", game->moves);
	}
	check_end_game(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->player_y + 1][game->player_x] != '1')
	{
		if (game->grid[game->player_y + 1][game->player_x] == 'C')
		{
			mlx_delete_image(game->mlx, game->img->gem);
			game->grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d\n", game->moves);
	}
	check_end_game(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->player_y][game->player_x + 1] != '1')
	{
		if (game->grid[game->player_y][game->player_x + 1] == 'C')
		{
			mlx_delete_image(game->mlx, game->img->gem);
			game->grid[game->player_y][game->player_x + 1] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d\n", game->moves);
	}
	check_end_game(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->player_y][game->player_x - 1] != '1')
	{
		if (game->grid[game->player_y][game->player_x - 1] == 'C')
		{
			mlx_delete_image(game->mlx, game->img->gem);
			game->grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d\n", game->moves);
	}
	check_end_game(game);
	return (game);
}