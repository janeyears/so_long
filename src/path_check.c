/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:50 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:34 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->gems--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

void	temp_map(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.gems = game->gems;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit_x = 0;
	temp.grid = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.grid)
		error_msg("Memory allocation for a struct has failed.");
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&temp, temp.player_y, temp.player_x);
	if (!(temp.exit_x == 1 && temp.gems == 0))
	{
		free_grid(temp.grid, temp.height);
		error_free("No valid path", game);
	}
	free_grid(temp.grid, temp.height);
}
