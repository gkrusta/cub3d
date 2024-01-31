/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:53 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/31 17:47:40 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	check_coordinate(t_game *game, t_pos *pixel_pos)
{
	if (pixel_pos->x < 0.0 || pixel_pos->y < 0.0)
		return (false);
	else if (pixel_pos->x >= game->data->max_cols)
		return (false);
	else if (pixel_pos->y >= game->data->rows)
		return (false);
	else
		return (true);
}

int	get_color(t_game *game, int i, int j)
{
	int		color;
	char	**mini_map;

	mini_map = game->data->map;
	if (mini_map[i][j] == WALL)
		color = MAP_WALL_COLOR;
	else if (mini_map[i][j] == 'N' || mini_map[i][j] == 'S' ||
		mini_map[i][j] == 'W' || mini_map[i][j] == 'E' ||
			mini_map[i][j] == EMPTY)
		color = MAP_BACKGROUND_COLOR;
	else
		color = MAP_EMPTY_COLOR;
	return (color);
}

// The loop iterates through the rows and columns of the mini-map and 
// calculates the corresponding pixel positions based on the map start
// position and the tile size
void	iterate_map(t_game *game, t_pos *map_start)
{
	int		i;
	int		j;
	int		color;
	t_pos	pixel_pos;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			pixel_pos.x = map_start->x + i * 0.05;
			pixel_pos.y = map_start->y + j * 0.05;
			if (check_coordinate(game, &pixel_pos))
			{
				color = get_color(game, pixel_pos.y, pixel_pos.x);
				mlx_put_pixel(game->image, i, j, color);
			}
			else
				mlx_put_pixel(game->image, i, j, MAP_EMPTY_COLOR);
			j++;
		}
		i++;
	}
}

void	init_mini_map(t_game *game)
{
	t_pos	map_start;
	int		i;
	int		j;

	map_start.x = game->player->x - 5.0;
	map_start.y = game->player->y - 5.0;
	iterate_map(game, &map_start);
	i = 98;
	while (i <= 102)
	{
		j = 98;
		while (j <= 102)
		{
			mlx_put_pixel(game->image, i, j, MAP_PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
