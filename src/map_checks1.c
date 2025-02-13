/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:38:13 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 13:58:41 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_invalid_symbols(int i, char *map)
{
	if (!(ft_strchr("01CEP\n", i)))
	{
		free(map);
		error_msg_exit("Map contains invalid symbols");
	}
}

void	check_map_ber(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
		error_msg_exit("Map is not a .ber file");
}

void	check_map_rectangle(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			free_grid(map, i);
			error_msg_exit("Map is not a rectangle");
		}
		i++;
	}
}

void	validate_map_elements(char *map)
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
			check_invalid_symbols(map[i], map);
	}
	if (player != 1 || exit != 1 || gems < 1)
	{
		free(map);
		error_msg_exit("Invalid map");
	}
}
