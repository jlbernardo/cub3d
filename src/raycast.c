/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/02 18:59:42 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	absolute(int num);

void	raycast(t_game *cub)
{
	int		i;
	float	atan;

	i = 0;
	cub->ray.angle = cub->p1.angle;
	cub->ray.count = 1;
	while (i < cub->ray.count)
	{
		// HORIZONTAL COLLISION DETECTION 
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
		while (cub->ray.depth_of_field < 8)
		{
			if(cub->ray.ray_x >= 0 && cub->ray.ray_y >= 0)
			{
				if (cub->map.matrix[(int)cub->ray.ray_x / SIZE][(int)cub->ray.ray_y / SIZE] == '1')
				{
					cub->ray.depth_of_field = 8;
					line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
				}
			}
			else if(cub->ray.ray_x < 0 || cub->ray.ray_y < 0)
				return ;
			else
			{
				cub->ray.ray_x += cub->ray.x_offset;
				cub->ray.ray_y += cub->ray.y_offset;
				cub->ray.depth_of_field++;
			}				
		}
		// line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
		//VERTICAL COLLISION DETECTION
	// 	cub->ray.depth_of_field = 0;
	// 	atan = 1.0 * atan;
	// 	if ((float)sin(cub->ray.angle) > 0.001)
	// 	{
	// 		cub->ray.ray_y = (((int)cub->p1.y >> 6) << 6) - 0.0001;
	// 		cub->ray.ray_x = (cub->p1.y - cub->ray.ray_y) * atan + cub->p1.x;
	// 		cub->ray.y_offset = -SIZE;
	// 		cub->ray.x_offset = -cub->ray.y_offset * atan;
	// 	}
	// 	else if ((float)sin(cub->ray.angle) < -0.001)
	// 	{
	// 		cub->ray.ray_y = (((int)cub->p1.y >> 6) << 6) + SIZE;
	// 		cub->ray.ray_x = (cub->p1.y - cub->ray.ray_y) * atan + cub->p1.x;
	// 		cub->ray.y_offset = SIZE;
	// 		cub->ray.x_offset = -cub->ray.y_offset * atan;
	// 	}
	// 	else
	// 	{
	// 		cub->ray.ray_x = cub->p1.x;
	// 		cub->ray.ray_y = cub->p1.y;
	// 		cub->ray.depth_of_field = 8;
	// 	}
	// 	while (cub->ray.depth_of_field < 8)
	// 	{
	// 		if (cub->map.matrix[(int)cub->ray.ray_x / SIZE][(int)cub->ray.ray_y / SIZE] == '1')
	// 		{
	// 			cub->ray.depth_of_field = 8;
	// 			line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
	// 		}
	// 		else
	// 		{
	// 			cub->ray.ray_x += cub->ray.x_offset;
	// 			cub->ray.ray_y += cub->ray.y_offset;
	// 			cub->ray.depth_of_field++;
	// 		}
	// 	}
		i++;
	}
	// line(cub, cub->p1.x, cub->p1.y, cub->ray.ray_x, cub->ray.ray_y);
}
