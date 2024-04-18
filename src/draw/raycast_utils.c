/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/17 23:59:29 by julberna         ###   ########.fr       */
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
		cub->ray.side = SO;
	if (axis == Y && cub->ray.dir.y <= 0)
		cub->ray.side = NO;
}

void	draw_line(t_game *cub, int i)
{
	int			rev;
	t_coord		end;
	t_coord		start;

	if (cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '2')
		cub->ray.closed_door = true;
	check_open_door(cub);
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
	rev = 0;
	if (cub->ray.dir.y > 0)
		rev = cub->ray.side % 2;
	if (cub->ray.dir.x > 0 && cub->ray.side % 2 == 0)
		rev = 3;
	if (cub->ray.open_door)
		put_texture(cub, start, end, OPEN_DOOR + rev + (cub->ray.side % 2));
}

void	check_open_door(t_game *cub)
{
	if (cub->ray.side == EA && (int)cub->ray.map.x - 1 > 0
		&& cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x - 1] == '3')
		cub->ray.open_door = true;
	else if (cub->ray.side == WE && (int)cub->ray.map.x + 1 <= cub->map.x
		&& cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x + 1] == '3')
		cub->ray.open_door = true;
	else if (cub->ray.side == NO && (int)cub->ray.map.y + 1 > 0
		&& cub->map_matrix[(int)cub->ray.map.y + 1][(int)cub->ray.map.x] == '3')
		cub->ray.open_door = true;
	else if (cub->ray.side == SO && (int)cub->ray.map.y - 1 <= cub->map.y
		&& cub->map_matrix[(int)cub->ray.map.y - 1][(int)cub->ray.map.x] == '3')
		cub->ray.open_door = true;
}

void	calculate_frames_per_second(t_game *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = mlx_get_time();
	frame_time = (cub->time - cub->old_time) / 1000.0;
}
