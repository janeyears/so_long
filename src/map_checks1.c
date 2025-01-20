/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:38:13 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/20 15:57:41 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	check_invalid_symbols(int i)
{
	if(!(ft_strchr("PEC01X\n", i)))
		error_msg("Map contains invalid symbols");
}

void	check_map_content(char *map)
{
	int	player;
	int	exit;
	int	gems;
	int	i;

	player = 0;
	exit = 0;
	gems = 0;
	i = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'C')
			gems++;
		else
			check_invalid_symbols(map[i]);
	}
	if (player != 1|| exit != 1 || gems < 1)
		error_msg("Invalid map");
}

void	check_map_ber(char *file)
{
	size_t	len;
	
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
		error_msg("Map is not a .ber file");
}

void	check_map_rectangle(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			error_msg("Map is not a rectangle");
		i++;
	}
}