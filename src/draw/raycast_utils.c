/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/21 00:04:26 by aperis-p         ###   ########.fr       */
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
		cub->ray.side = EA;
	if (axis == X && cub->ray.dir.x <= 0)
		cub->ray.side = WE;
	if (axis == Y && cub->ray.dir.y > 0)
		cub->ray.side = NO;
	if (axis == Y && cub->ray.dir.y <= 0)
		cub->ray.side = SO;
}

void	draw_ceiling_floor(t_game *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub->ceiling_floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->ceiling_floor)
		cuberror("Oops, had a problem with the background. ˙◠˙", cub);
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
	char				*fps_string;
	static mlx_image_t	*fps_img;
	static int			fps_count;
	int					current_second;

	fps_count += 1;
	current_second = (int)mlx_get_time();
	if ((int)cub->time < current_second)
	{
		fps_string = ft_strjoin("FPS: ", ft_itoa(fps_count));
		fps_count = 0;
		cub->time = mlx_get_time();
		if (fps_img)
			mlx_delete_image(cub->mlx, fps_img);
		fps_img = mlx_put_string(cub->mlx, fps_string, 20, HEIGHT - 35);
		mlx_resize_image(fps_img, 100, 25);
		free(fps_string);
	}
}
