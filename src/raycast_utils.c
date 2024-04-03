/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:28:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 02:01:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_ray_setup(t_game *cub, int i)
{
	cub->ray.hit = false;
	cub->ray.camera_x = 2 * i / (double)WIDTH - 1;
	cub->ray.dir.x = cub->direction.x + cub->camera_plane.x * cub->ray.camera_x;
	cub->ray.dir.y = cub->direction.y + cub->camera_plane.y * cub->ray.camera_x;
	cub->ray.map = coordinate(cub->p1.x, cub->p1.y);
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
		cub->ray.side_dist.x = (cub->ray.map.x + 1 - cub->p1.x)
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
		cub->ray.side_dist.y = (cub->ray.map.y + 1 - cub->p1.y)
			* cub->ray.delta_dist.y;
	}
}
