/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:22:49 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/18 17:29:57 by ekashirs         ###   ########.fr       */
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

static char	*read_and_join_lines(int fd, char *map_str)
{
	char	*tmp;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = ft_strjoin(map_str, line);
			if (!tmp)
			{
				free(line);
				free(map_str);
				close(fd);
				return (NULL);
			}
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

char	*read_map(char *map)
{
	char	*map_str;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_str = ft_calloc(1, 1);
	if (!map_str)
	{
		close(fd);
		return (NULL);
	}
	map_str = read_and_join_lines(fd, map_str);
	return (map_str);
}
