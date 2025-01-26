/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:34:44 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/24 12:42:13 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	remove_gem(t_game *game, int y, int x)
{
	int	gem_count;

	gem_count = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (gem_count < game->img->gem->count)
	{
		if (game->img->gem->instances[gem_count].x == x
			&& game->img->gem->instances[gem_count].y == y)
		{
			game->img->gem->instances[gem_count].enabled = false;
		}
		gem_count++;
	}
}

t_game	*move_up(t_game *game)
{
	if (game->grid[game->player_y - 1][game->player_x] != '1'
		&& game->grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y - 1][game->player_x] == 'C')
		{
			remove_gem(game, game->player_y - 1, game->player_x);
			game->grid[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d", game->moves);
	}
	check_game_status(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->grid[game->player_y + 1][game->player_x] != '1'
		&& game->grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y + 1][game->player_x] == 'C')
		{
			remove_gem(game, game->player_y + 1, game->player_x);
			game->grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d", game->moves);
	}
	check_game_status(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->grid[game->player_y][game->player_x + 1] != '1'
		&& game->grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x + 1] == 'C')
		{
			remove_gem(game, game->player_y, game->player_x + 1);
			game->grid[game->player_y][game->player_x + 1] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d", game->moves);
	}
	check_game_status(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->grid[game->player_y][game->player_x - 1] != '1'
		&& game->grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x - 1] == 'C')
		{
			remove_gem(game, game->player_y, game->player_x - 1);
			game->grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->moves += 1;
		ft_printf("%d", game->moves);
	}
	check_game_status(game);
	return (game);
}