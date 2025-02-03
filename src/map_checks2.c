/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:56 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:42 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_empty(char *map)
{
	if (!map[0])
		error_msg("Map is empty.");
}

void	check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
			error_msg("There are empty lines on the map.");
		i++;
	}
}

void	check_walls(t_game *game)
{
	{
	size_t	i;

	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1')
			error_free("The map is not surrounded by walls.", game);
		if (game->grid[i][game->width -1] != '1')
			error_free("The map is not surrounded by walls.", game);
		i++;
	}
	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
			error_free("The map is not surrounded by walls.", game);
		if (game->grid[game->height -1][i] != '1')
			error_free("The map is not surrounded by walls.", game);
		i++;
	}
}
}
