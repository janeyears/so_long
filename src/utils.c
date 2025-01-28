/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/28 17:18:37 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

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