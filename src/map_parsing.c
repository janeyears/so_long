/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:22:49 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 13:20:13 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <fcntl.h>

size_t	count_rows(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

size_t	count_gems(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	gems;

	y = 0;
	gems = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
			{
				gems++;
			}
			x++;
		}
		y++;
	}
	return (gems);
}

char	*read_map(char *map)
{
	char	*line;
	char	*map_str;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	map_str = ft_calloc(1, 1);
	if (!map_str)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = ft_strjoin(map_str, line);
			free(map_str);
			map_str = tmp;
			free (line);
		}
		else
			break ;
	}
	close (fd);
	return (map_str);
}
