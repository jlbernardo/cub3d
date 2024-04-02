/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/02 00:01:13 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *cub, int i)
{
	double		direction;
	t_point		delta_dist;
	t_point		side_dist;
	t_point		map;
	t_vector	ray_dir;

	while (i < WIDTH)
	{
		direction = 2 * i / (double)WIDTH - 1;
		ray_dir.x = cub->p1.dir.x + cub->p1.plane.x * direction;
		ray_dir.y = cub->p1.dir.y + cub->p1.plane.y * direction;
	}
}
