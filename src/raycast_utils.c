/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/04 20:39:48 by aperis-p         ###   ########.fr       */
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

void draw_ceiling_floor(t_game *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	cub->ceiling_floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	while (x <= HEIGHT)
	{
		while (y <= WIDTH)
		{
			if(x < HEIGHT / 2)
				mlx_put_pixel(cub->ceiling_floor, y, x, 0xEEF5FFff);
			else
				mlx_put_pixel(cub->ceiling_floor, y, x, 0xA5DD9Bff);
			y++;	
		}
		y = 0;
		x++;
	} 
	mlx_image_to_window(cub->mlx, cub->ceiling_floor, 0, 0);
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
	if (cub->ray.side == NO)
		line(cub, start, end, 0x00f5d4ff);
	else if (cub->ray.side == SO)
		line(cub, start, end, 0x00bbf9ff);
	else if (cub->ray.side == EA)
		line(cub, start, end, 0xfee440ff);
	else if (cub->ray.side == WE)
		line(cub, start, end, 0xf15bb5ff);
}

void	calculate_frames_per_second(t_game *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = mlx_get_time();
	frame_time = (cub->time - cub->old_time) / 1000.0;
}
