/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:50 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/18 14:54:16 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	path_search(t_game *temp, size_t y, size_t x)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == 'C')
		temp->gems--;
	if (temp->map[y][x] == 'E')
		temp->exit_x = 1;
	temp->map[y][x] = '1';
	if (path_search(temp, y + 1, x))
		return (1);
	if (path_search(temp, y - 1, x))
		return (1);
	if (path_search(temp, y, x + 1))
		return (1);
	if (path_search(temp, y, x - 1))
		return (1);
	return (0);
}

static void	init_temp_map(t_game *game, t_game *temp)
{
	size_t	i;

	temp->height = game->height;
	temp->width = game->width;
	temp->gems = game->gems;
	temp->player_x = game->player_x;
	temp->player_y = game->player_y;
	temp->exit_x = 0;
	temp->map = malloc(temp->height * sizeof(char *));
	if (!temp->map)
		error_free("Memory allocation for a temp map struct has failed.", game);
	i = 0;
	while (i < temp->height)
	{
		temp->map[i] = ft_strdup(game->map[i]);
		if (!temp->map[i])
		{
			free_map_arr(temp->map);
			error_free("Allocation in ft_strdup has failed", game);
		}
		i++;
	}
}

static void	validate_path_and_clean(t_game *game, t_game *temp)
{
	path_search(temp, temp->player_y, temp->player_x);
	if (!(temp->exit_x == 1 && temp->gems == 0))
	{
		free_grid(temp->map, temp->height);
		error_free("No valid path", game);
	}
	free_grid(temp->map, temp->height);
}

void	temp_map(t_game *game)
{
	t_game	temp;

	init_temp_map(game, &temp);
	validate_path_and_clean(game, &temp);
}
