/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:34:44 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/12 17:59:42 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	remove_gem(t_game *game, int y, int x)
{
	size_t i;
	
	i = 0;
	while (i < game->gems)
	{
		if (game->img->gem->instances[i].x == (int32_t)x * PIXELS &&
			game->img->gem->instances[i].y == (int32_t)y * PIXELS)
		{
			game->img->gem->instances[i].enabled = false;
			break;
		}
		i++;
	}
}

t_game	*move_up(t_game *game)
{

	if (game->grid[game->player_y - 1][game->player_x] != '1')
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
			remove_gem(game, game->player_y + 1, game->player_x);
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
			remove_gem(game, game->player_y, game->player_x + 1);
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
			remove_gem(game, game->player_y, game->player_x - 1);
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
