/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/18 16:27:37 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *cub)
{
	int	i;

	i = -1;
	if (cub->screen)
		mlx_delete_image(cub->mlx, cub->screen);
	cub->screen = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->screen)
		cuberror("Oops, the game just broke. ˙◠˙", cub);
	while (++i < WIDTH)
	{
		initial_ray_setup(cub, i);
		calculate_delta_distance(cub);
		calculate_step_and_initial_side_distance(cub);
		calculate_wall_distance(cub);
		draw_line(cub, i);
	}
	mlx_image_to_window(cub->mlx, cub->screen, 0, 0);
}

void	initial_ray_setup(t_game *cub, int i)
{
	cub->time = mlx_get_time();
	cub->old_time = 0;
	cub->ray.hit = false;
	cub->ray.camera_x = 2 * i / (double)WIDTH - 1;
	cub->ray.map = coordinate((int)cub->p1.x, (int)cub->p1.y);
	cub->ray.dir.x = cub->direction.x + cub->camera_plane.x * cub->ray.camera_x;
	cub->ray.dir.y = cub->direction.y + cub->camera_plane.y * cub->ray.camera_x;
}

void	calculate_delta_distance(t_game *cub)
{
	if (cub->ray.dir.x == 0)
		cub->ray.delta_dist.x = 1e30;
	else
		cub->ray.delta_dist.x = fabs(1 / cub->ray.dir.x);
	if (cub->ray.dir.y == 0)
		cub->ray.delta_dist.y = 1e30;
	else
		cub->ray.delta_dist.y = fabs(1 / cub->ray.dir.y);
}

void	calculate_step_and_initial_side_distance(t_game *cub)
{
	if (cub->ray.dir.x < 0)
	{
		cub->ray.step.x = -1;
		cub->ray.side_dist.x = (cub->p1.x - cub->ray.map.x)
			* cub->ray.delta_dist.x;
	}
	else
	{
		cub->ray.step.x = 1;
		cub->ray.side_dist.x = (cub->ray.map.x + 1.0 - cub->p1.x)
			* cub->ray.delta_dist.x;
	}
	if (cub->ray.dir.y < 0)
	{
		cub->ray.step.y = -1;
		cub->ray.side_dist.y = (cub->p1.y - cub->ray.map.y)
			* cub->ray.delta_dist.y;
	}
	else
	{
		cub->ray.step.y = 1;
		cub->ray.side_dist.y = (cub->ray.map.y + 1.0 - cub->p1.y)
			* cub->ray.delta_dist.y;
	}
}
