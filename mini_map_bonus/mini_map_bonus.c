/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:53 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/29 17:56:23 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_game *game, char **map)
{
	int	tile;
	int	i;
	int	j;
	//tile = game->data;
	j = 0;
	while (map[i])
	{
		i = 0;
		while (map[j])
		{
			if (map[i][j] == EMPTY)
				// paint floor
			else if (map[i][j] == WALL)
				// paint wall
			else if (ft_strchr(map[i][j], ))
				// player
			j++;
		}
		i++;
	}
}

void	init_mini_map(t_game *game)
{
	game->mlx = mlx_init(200, 200, "cub3d_bonus", true);
	if (!game->mlx)
		exit_handler("mlx_init error", game);
	game->mini_map = mlx_new_image(game->mlx, 200, 200);
	mlx_image_to_window(game->mlx, game->mini_map, 0, 0);
	raycast(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
