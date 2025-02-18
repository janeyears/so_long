/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:56 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/14 15:26:53 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
