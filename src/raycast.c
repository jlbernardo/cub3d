/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 01:56:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	raycast(t_game *cub, int i)
{
	t_ray	ray;

	while (++i < WIDTH)
	{
		initial_ray_setup(&ray, cub, i);
		calculate_delta_distance(&ray);
		calculate_step_and_initial_side_distance(&ray, cub);
		calculate_wall_distance(&ray, cub);
		draw_line(cub, &ray, i);
	}
}

void	draw_line(t_game *cub, t_ray *ray, int i)
{
	int		line_height;
	t_coord	start;
	t_coord	end;

	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	start.y = i;
	start.x = -line_height / 2 + HEIGHT / 2;
	if (start.x < 0)
		start.x = 0;
	end.y = i;
	end.x = line_height / 2 + HEIGHT / 2;
	if (end.x >= HEIGHT)
		end.x = HEIGHT - 1;
	if (ray->side == X)
		line(cub, start, end, 0x21F2FCFF);
	else
		line(cub, start, end, 0x111111FF);
}

void	calculate_wall_distance(t_ray *ray, t_game *cub)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = X;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = Y;
		}
		if (cub->map_matrix[(int)ray->map.y][(int)ray->map.x] == '1')
			ray->hit = true;
	}
	if (ray->side == X)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}
