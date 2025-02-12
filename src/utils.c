/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/12 16:44:14 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void check_end_game(t_game *game)
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
void	free_map_arr_exit(char **map_arr)
{
	int i = 0;

	while (map_arr[i] != NULL)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
	exit(1);
}

void	free_map_arr(char **map_arr)
{
	int i = 0;

	while (map_arr[i] != NULL)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}

