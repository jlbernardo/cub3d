/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/09 01:25:00 by julberna         ###   ########.fr       */
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
	while (x <= HEIGHT)
	{
		while (y <= WIDTH)
		{
			if (x < (int)(HEIGHT / HORIZON))
				mlx_put_pixel(cub->ceiling_floor, y, x, 0xe7fbffff);
			else
				mlx_put_pixel(cub->ceiling_floor, y, x, 0x344e41ff);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(cub->mlx, cub->ceiling_floor, 0, 0);
}

void	draw_line(t_game *cub, int i)
{
	int			y;
	int			line_height;
	double		texture_position;
	double		texture_x;
	double		texture_y;
	double		wall_x;
	double		step;
	t_coord		end;
	t_coord		start;
	int	color;

	line_height = (int)(HEIGHT / cub->ray.perp_wall_dist);
	start.y = i;
	start.x = (int)(-line_height / HORIZON + HEIGHT / HORIZON);
	if (start.x < 0)
		start.x = 0;
	end.y = i;
	end.x = (int)(line_height / HORIZON + HEIGHT / HORIZON);
	if (end.x >= HEIGHT)
		end.x = HEIGHT - 1;
	if (cub->ray.side == NO)
	{
		wall_x = cub->p1.x + cub->ray.perp_wall_dist * cub->ray.dir.x;
		wall_x -= floor(wall_x);
		texture_x = (wall_x * (double)512);
		step = 1.0 * 512 / line_height;
		texture_position = (start.x - HEIGHT / HORIZON + line_height / HORIZON) * step;
		y = start.x;
		ft_bzero(cub->buffer, 980);
		while (y < end.x)
		{
			texture_y = (int)(texture_position) & (512 - 1);
			texture_position += step;
			color = get_color(cub, texture_x, texture_y);
			cub->buffer[y] = color;
			y++;
		}
		line(cub, start, end, 0x00000000, cub->buffer);
		ft_bzero(cub->buffer, 980);
	}
	else if (cub->ray.side == SO)
		line(cub, start, end, 0xffe45eff, NULL);
	else if (cub->ray.side == EA)
		line(cub, start, end, 0x7fc8f8ff, NULL);
	else if (cub->ray.side == WE)
		line(cub, start, end, 0xf9f9f9ff, NULL);
}

int	get_color(t_game *cub, double texture_x, double texture_y)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int		*p;

	p = (int *)cub->wall->pixels + 4 + (int)texture_x + (int)texture_y * 512;
	r = *(p + 0);
	g = *(p + 1);
	b = *(p + 2);
	a = 255;
	// r = cub->wall->pixels[(uint32_t)(512 * texture_y + texture_x + 0)] & 0xFF;
	// g = cub->wall->pixels[(uint32_t)(512 * texture_y + texture_x + 1)] & 0xFF;
	// b = cub->wall->pixels[(uint32_t)(512 * texture_y + texture_x + 2)] & 0xFF;
	// a = cub->wall->pixels[(uint32_t)(512 * texture_y + texture_x + 3)] & 0xFF;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	calculate_frames_per_second(t_game *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = mlx_get_time();
	frame_time = (cub->time - cub->old_time) / 1000.0;
}
