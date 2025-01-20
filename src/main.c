/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:23:05 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/20 16:18:30 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int main (int argc, char **argv)
{
	t_game	*game;
	t_img	*textures;

	if (argc != 2)
		error_msg("Invalid number of arguments.");
	check_map_ber(argv[1]);
	return (0);
	
}