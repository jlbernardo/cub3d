/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 02:00:58 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	raycast(t_game *cub, int i)
{
	while (++i < WIDTH)
	{
		initial_ray_setup(cub, i);
		calculate_delta_distance(cub);
		calculate_step_and_initial_side_distance(cub);
		calculate_wall_distance(cub);
		draw_line(cub, i);
	}
}

void	draw_line(t_game *cub, int i)
{
	int		line_height;
	t_coord	start;
	t_coord	end;

	line_height = (int)(HEIGHT / cub->ray.perp_wall_dist);
	start.y = i;
	start.x = -line_height / 2 + HEIGHT / 2;
	if (start.x < 0)
		start.x = 0;
	end.y = i;
	end.x = line_height / 2 + HEIGHT / 2;
	if (end.x >= HEIGHT)
		end.x = HEIGHT - 1;
	if (cub->ray.side == X)
		line(cub, start, end, 0x21F2FCFF);
	else
		line(cub, start, end, 0x111111FF);
}

void	calculate_wall_distance(t_game *cub)
{
	while (!cub->ray.hit)
	{
		if (cub->ray.side_dist.x < cub->ray.side_dist.y)
		{
			cub->ray.side_dist.x += cub->ray.delta_dist.x;
			cub->ray.map.x += cub->ray.step.x;
			cub->ray.side = X;
		}
		else
		{
			cub->ray.side_dist.y += cub->ray.delta_dist.y;
			cub->ray.map.y += cub->ray.step.y;
			cub->ray.side = Y;
		}
		if (cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '1')
			cub->ray.hit = true;
	}
	if (cub->ray.side == X)
		cub->ray.perp_wall_dist = cub->ray.side_dist.x - cub->ray.delta_dist.x;
	else
		cub->ray.perp_wall_dist = cub->ray.side_dist.y - cub->ray.delta_dist.y;
}
