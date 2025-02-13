/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:56 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 13:59:06 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_empty_file_lines(char *map)
{
	size_t	i;

	if (!map[0])
	{
		free(map);
		error_msg_exit("Map is empty.");
	}
	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
		{
			free(map);
			error_msg_exit("There are empty lines on the map.");
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			error_free("The map is not surrounded by walls.", game);
		if (game->map[i][game->width -1] != '1')
			error_free("The map is not surrounded by walls.", game);
		i++;
	}
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			error_free("The map is not surrounded by walls.", game);
		if (game->map[game->height -1][i] != '1')
			error_free("The map is not surrounded by walls.", game);
		i++;
	}
}
