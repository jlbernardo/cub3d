/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 22:12:36 by julberna         ###   ########.fr       */
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

void	calculate_frames_per_second(t_game *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = mlx_get_time();
	frame_time = (cub->time - cub->old_time) / 1000.0;
	cub->move_speed = frame_time * 5.0;
	cub->rotation_speed = frame_time * 3.0;
}
