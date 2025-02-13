/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:19 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/13 13:45:33 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	if (game->img)
		free(game->img);
}

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
}

void	error_msg_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_free(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free_game(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game)
		free(game);
	exit(1);
}
