/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/17 15:29:32 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_distance(t_game *cub)
{
	while (!cub->ray.hit)
	{
		if (cub->ray.side_dist.x < cub->ray.side_dist.y)
		{
			cub->ray.side_dist.x += cub->ray.delta_dist.x;
			cub->ray.map.x += cub->ray.step.x;
			wall_side(cub, X);
		}
		else
		{
			cub->ray.side_dist.y += cub->ray.delta_dist.y;
			cub->ray.map.y += cub->ray.step.y;
			wall_side(cub, Y);
		}
		if (cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '1'
			|| cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '2')
			cub->ray.hit = true;
	}
	if (cub->ray.side == EA || cub->ray.side == WE)
		cub->ray.perp_wall_dist = cub->ray.side_dist.x - cub->ray.delta_dist.x;
	else
		cub->ray.perp_wall_dist = cub->ray.side_dist.y - cub->ray.delta_dist.y;
}

void	wall_side(t_game *cub, int axis)
{
	if (axis == X && cub->ray.dir.x > 0)
		cub->ray.side = EA;
	if (axis == X && cub->ray.dir.x <= 0)
		cub->ray.side = WE;
	if (axis == Y && cub->ray.dir.y > 0)
		cub->ray.side = NO;
	if (axis == Y && cub->ray.dir.y <= 0)
		cub->ray.side = SO;
}

void	draw_line(t_game *cub, int i)
{
	t_coord		end;
	t_coord		start;

	if (cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '2')
		cub->ray.door = true;
	cub->ray.line_height = (int)(HEIGHT / cub->ray.perp_wall_dist) + 1;
	start.y = i;
	start.x = (int)(-cub->ray.line_height / HORIZON + HEIGHT / HORIZON);
	if (start.x < 0)
		start.x = 0;
	end.y = i;
	end.x = (int)(cub->ray.line_height / HORIZON + HEIGHT / HORIZON);
	if (end.x >= HEIGHT)
		end.x = HEIGHT - 1;
	put_texture(cub, start, end, cub->ray.side);
}

void	calculate_frames_per_second(t_game *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = mlx_get_time();
	frame_time = (cub->time - cub->old_time) / 1000.0;
}
