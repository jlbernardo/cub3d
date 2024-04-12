/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 15:36:12 by julberna         ###   ########.fr       */
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
		if (cub->map_matrix[(int)cub->ray.map.y][(int)cub->ray.map.x] == '1')
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
		cub->ray.side = WE;
	if (axis == X && cub->ray.dir.x <= 0)
		cub->ray.side = EA;
	if (axis == Y && cub->ray.dir.y > 0)
		cub->ray.side = SO;
	if (axis == Y && cub->ray.dir.y <= 0)
		cub->ray.side = NO;
}

void	draw_ceiling_floor(t_game *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub->ceiling_floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	while (x < HEIGHT)
	{
		while (y < WIDTH)
		{
			if (x < (int)(HEIGHT / HORIZON))
				mlx_put_pixel(cub->ceiling_floor, y, x, cub->map_data.c_color);
			else
				mlx_put_pixel(cub->ceiling_floor, y, x, cub->map_data.f_color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(cub->mlx, cub->ceiling_floor, 0, 0);
}

void	draw_line(t_game *cub, int i)
{
	t_coord		end;
	t_coord		start;

	cub->ray.line_height = (int)(HEIGHT / cub->ray.perp_wall_dist);
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
