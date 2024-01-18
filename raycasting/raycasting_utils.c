/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:55 by gkrusta           #+#    #+#             */
/*   Updated: 2024/01/18 15:36:34 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_fractional_part(t_pos *hit_point)
{
	double	x_fractional;
	double	y_fractional;

	x_fractional = modf(hit_point->x, &x_fractional);
	y_fractional = modf(hit_point->y, &y_fractional);

	if (y_fractional == (int)hit_point->y)
		return (x_fractional);
	else
		return (y_fractional);
}

mlx_texture_t	get_rays_texture_extension(t_game *game, t_pos *hit_point, t_ray *ray)
{
	//mlx_texture_t	texture;

	if (ray->quadrant == 3)
	{
		if (hit_point->y == (int)hit_point->y)
			return *(game->textures->south);
		else
			return *(game->textures->west);
	}
	else
	{
		if (hit_point->y == (int)hit_point->y)
			return *(game->textures->south);
		else
			return *(game->textures->east);
	}
}

mlx_texture_t	get_rays_texture(t_game *game, t_pos *hit_point, t_ray *ray)
{
	//mlx_texture_t	texture;

	if (ray->quadrant == 1)
	{
		if (hit_point->y == (int)hit_point->y)
			return *(game->textures->north);
		else
			return *(game->textures->east);
	}
	else if (ray->quadrant == 2)
	{
		if (hit_point->y == (int)hit_point->y)
			return *(game->textures->north);
		else
			return *(game->textures->east);
	}
	else
		return (get_rays_texture_extension(game, hit_point, ray));
}

double	get_absoulte(double ray_angle, double view_angle)
{
	return (fabs(ray_angle - view_angle));
}

void	align_coordinates(t_ray *ray, int *i, int *j, char crossing)
{
	if (crossing == 'y' && ray->sign.x == -1)
		--(*i);
	else if (crossing == 'x' && ray->sign.y == -1)
		--(*j);
	else
		return ;
}

bool	wall_check(t_data *data, t_ray *ray, t_pos step, char crossing)
{
	int		i;
	int		j;
	char	**map;

	i = (int)step.x;
	j = (int)step.y;
	map = data->map;
	align_coordinates(ray, &i, &j, crossing);
	if (abs(j + 1) > data->rows && crossing == 'y')
		return (true);
	if (abs(i + 1) > data->max_cols && crossing == 'x')
		return (true);
	printf("from crossing %c:\ni: %d and j: %d\n", crossing, i, j);
	if (map[j][i] == '1')
		return (true);
	return (false);
}