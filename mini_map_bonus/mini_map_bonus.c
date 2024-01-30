/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:53 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/30 12:51:32 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_pos	get_maps_size()
{
	t_pos	players_field;

	players_field.x = modf(x, &players_field.x);
	players_field.y = modf(y, &players_field.y);
	
}

void	fill_cell(t_game *game, int x, int y, int color)
{
	int		tile_start_x;
	int		tile_start_y;

	if (color == MAP_PLAYER_COLOR)
		fill_players_cell(x, y);
	tile_start_x = x * 20;
	while (tile_start_x < tile_start_x + 20)
	{
		tile_start_x++;
		tile_start_y = y * 20;
		while (tile_start_y < tile_start_y + 20)
		{
			mlx_put_pixel(game->mini_map, x, y, color);
			tile_start_y++;
		}
	}
}

void	draw_map(t_game *game, char **map, int *i, int *j)
{
	int	color;
	int	tmp_j;

	while (map[i])
	{
		tmp_j = j;
		while (j < game->data->max_cols && map[i][j])
		{
			if (map[i][j] == WALL)
				color = MAP_WALL_COLOR;
			else if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E')
				color = MAP_PLAYER_COLOR;
			else
				color = MAP_EMPTY_COLOR;
			fill_cell(game, game->player->y, game->player->x, color);
			tmp_j++;
		}
		i++;
	}
}

void	iterate_map(t_game *game, int *x, int *y)
{
	if (y < 0)
	{
		
		iterate_map(game, x, y + 1);
	}
	else if (x < 0)
	{
		
		iterate_map(game, x + 1, y);
	}
	else if (y > game->data->max_cols)
	{
		
		iterate_map(game, x, y + 1);
	}
	else if (x > game->data->rows)
	{
		*
		iterate_map(game, x, y + 1);
	}
}

void	init_mini_map(t_game *game)
{
	t_pos	map_start;

	map_start.x = (int)(game->player->x - 5.0);
	map_start.y = (int)(game->player->y - 5.0);
	iterate_map(game, &map_start.x, &map_start.y);
	game->mini_map = mlx_new_image(game->mlx, 198, 198);
	mlx_image_to_window(game->mlx, game->mini_map, 0, 0);
	draw_map(game, game->data->map, map_start.y, map_start.x);
	
}
