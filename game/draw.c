/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:12:39 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/18 18:11:34 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_and_ceiling(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			mlx_put_pixel(game->image, x, y, game->textures->ceiling_color);
			y++;
		}
		while (y < WIN_HEIGHT)
		{
			mlx_put_pixel(game->image, x, y, game->textures->floor_color);
			y++;
		}
		x++;
	}
}

// test function
void	draw_texture(t_game	*game, mlx_texture_t *texture)
{
	u_int32_t	y;
	u_int32_t	x;

	x = 0;
	while (x < texture->width * 12)
	{
		y = 0;
		while (y < texture->height * 12)
		{
			mlx_put_pixel(game->image, x, y,
				get_texture_pixel_color(texture, y % 64, x % 64));
			y++;
		}
		x++;
	}
}

void	draw_column(t_game *game, int x, int w_start, int w_end)
{
	int	y;

	y = 0;
	while (y <= WIN_HEIGHT)
	{
		if (y >= w_start && y <= w_end)
			mlx_put_pixel(game->image, x, y,
				get_texture_pixel_color(game->pixel_info->texture,
					(y - w_start) % (int)(game->pixel_info->texture->height), game->pixel_info->wall_hit));
		y++;
	}
}
// Information needed:
// ray length
// What texture was hit
// the x pos in which the texture was hit which is:
// (floating-point part of x coordinate * texture_width)
void	calc_wall_and_draw(t_game *game, int x)
{
	int	w_height;
	int	w_start;
	int	w_end;

	w_height = WIN_HEIGHT / game->pixel_info->distance; // part of some struct
	w_start = (WIN_HEIGHT / 2) - (w_height / 2);
	if (w_start < 0)
		w_start = 0;
	w_end = (WIN_HEIGHT / 2) + (w_height / 2);
	if (w_end > WIN_HEIGHT)
		w_end = WIN_HEIGHT;
	draw_column(game, x, w_start, w_end);
}