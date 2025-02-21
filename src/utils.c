/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/21 14:48:43 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_end_game(t_game *game)
{
	if (game->collected == game->gems)
	{
		if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		{
			mlx_close_window(game->mlx);
			ft_printf("Congrats! You have found all gems\n");
		}
	}
}

size_t	get_player_position(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_exit_position(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	free_map_arr(char **map_arr)
{
	int	i;

	i = 0;
	if (map_arr[i] == NULL)
	{
		free(map_arr);
		return ;
	}
	while (map_arr[i] != NULL)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}

void	free_grid(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
