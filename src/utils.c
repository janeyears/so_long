/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/12 14:26:44 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void check_end_game(t_game *game)
{
    if (game->collected == game->gems)
    {
        if (game->player_x == game->exit_x && game->player_y == game->exit_y)
        {
            mlx_close_window(game->mlx);
            ft_printf("Congrats! You have found all gems\n");
        }
    }
}

void	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->grid[i]);
		i++;
	}
	if (game->grid)
		free(game->grid);
	if (game->img)
		free(game->img);
	if (game)
		free(game);
}

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void error_free(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free_game(game);
	mlx_terminate(game->mlx);
	if (game)
		free(game);
	exit(1);
}
