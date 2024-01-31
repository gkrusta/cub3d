/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:11:49 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/31 14:01:55 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Angle = 1 if rotating left and -1 if rotating right
void	rotate(t_game *game, int angle)
{
	double	new_angle;

	new_angle = game->player->view_angle + (ROTATION_SPEED * angle);
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	else if (new_angle < 0)
		new_angle += 2 * M_PI;
	game->player->view_angle = new_angle;
	game->player->x_viewdir = cos(game->player->view_angle);
	game->player->y_viewdir = -sin(game->player->view_angle);
	raycast(game);
}
