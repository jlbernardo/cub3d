/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/01 21:05:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	absolute(int num);
void	line(t_game *cub, int x1, int y1, int x2, int y2);

void	raycast(t_game *cub)
{
	int		i;
	float	atan;

	i = 0;
	cub->ray.angle = cub->p1.angle;
	cub->ray.count = 1;
	while (i < cub->ray.count)
	{
		cub->ray.depth_of_field = 0;
		atan = (float)-tan(cub->ray.angle);
		if ((float)cos(cub->ray.angle) > 0.001)
		{
			cub->ray.ray_x = (((int)cub->p1.x >> 6) << 6)  + SIZE;
			cub->ray.ray_y = (cub->p1.x - cub->ray.ray_x) * atan + cub->p1.y;
			cub->ray.x_offset = SIZE;
			cub->ray.y_offset = -cub->ray.x_offset * atan;
		}
		else if ((float)cos(cub->ray.angle) < -0.001)
		{
			cub->ray.ray_x = (((int)cub->p1.x >> 6) << 6) - 0.0001;
			cub->ray.ray_y = (cub->p1.x - cub->ray.ray_x) * atan + cub->p1.y;
			cub->ray.x_offset = -SIZE;
			cub->ray.y_offset = -cub->ray.x_offset * atan;
		}
		else
		{
			cub->ray.ray_x = cub->p1.x;
			cub->ray.ray_y = cub->p1.y;
			cub->ray.depth_of_field = 8;
		}
		if (error * 2 <= dx)
		{
			if (cub->map.matrix[(int)cub->ray.ray_x / SIZE][(int)cub->ray.ray_y / SIZE] == '1')
			{
				cub->ray.depth_of_field = 8;
			}
			else
			{
				cub->ray.ray_x += cub->ray.x_offset;
				cub->ray.ray_y += cub->ray.y_offset;
				cub->ray.depth_of_field++;
			}
		}
		line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
		i++;
	}
	
	// while (i < cub->ray.count)
	// {
	// 	cub->ray.depth_of_field = 0;
	// 	atan = -tan(cub->ray.angle);
	// 	if (cub->ray.angle > PI / 2 && cub->ray.angle < 3 * PI / 2)
	// 	{
	// 		cub->ray.ray_x = cub->p1.x;
	// 		cub->ray.ray_y = (cub->p1.x - cub->ray.ray_x) * atan + cub->p1.y;
	// 		cub->ray.x_offset = -SIZE;
	// 		cub->ray.y_offset = -cub->ray.x_offset * atan;
	// 	}
	// 	if (cub->ray.angle < PI / 2 || cub->ray.angle > 3 * PI / 2)
	// 	{
	// 		cub->ray.ray_x = cub->p1.x + SIZE;
	// 		cub->ray.ray_y = (cub->p1.x - cub->ray.ray_x) * atan + cub->p1.y;
	// 		cub->ray.x_offset = SIZE;
	// 		cub->ray.y_offset = -cub->ray.x_offset * atan;
	// 	}
	// 	if (cub->ray.angle == 0 || cub->ray.angle == PI)
	// 	{
	// 		cub->ray.ray_x = cub->p1.x;
	// 		cub->ray.ray_y = cub->p1.y;
	// 		cub->ray.depth_of_field = 8;
	// 	}
	// 	while (cub->ray.depth_of_field < 8)
	// 	{
	// 		if (cub->ray.ray_x < (cub->map.x * SIZE) && cub->ray.ray_y < (cub->map.y * SIZE)
	// 			&& cub->map.matrix[cub->ray.ray_y / SIZE][cub->ray.ray_x / SIZE] == '1')
	// 			cub->ray.depth_of_field = 8;
	// 		else
	// 		{
	// 			cub->ray.ray_x += cub->ray.x_offset;
	// 			cub->ray.ray_y += cub->ray.y_offset;
	// 			cub->ray.depth_of_field++;
	// 		}
	// 	}
	// 	line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
	// 	i++;
	// }
}

