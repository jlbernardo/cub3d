/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:27:07 by julberna          #+#    #+#             */
/*   Updated: 2024/04/01 01:32:33 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	absolute(int num);
void	line(t_game *cub, int x1, int y1, int x2, int y2);

void	raycast(t_game *cub)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = cub->p1.x;
	y1 = cub->p1.y;
	x2 = cub->p1.x + cub->p1.delta_x * 5;
	y2 = cub->p1.y + cub->p1.delta_y * 5;
	line(cub, x1, y1, x2, y2);
}

void	line(t_game *cub, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;

	sx = 1;
	sy = 1;
	dx = absolute(x2 - x1);
	dy = absolute(y2 - y1);
	if (x1 > x2)
		sx = -1;
	if (y1 > y2)
		sy = -1;
	error = dx - dy;
	while (true)
	{
		mlx_put_pixel(cub->gen, y1, x1, 0x21F2FCFF);
		if (x1 == x2 && y1 == y2)
			break ;
		if (error * 2 >= -dy)
		{
			if (x1 == x2)
				break ;
			error -= dy;
			x1 += sx;
		}
		if (error * 2 <= dx)
		{
			if (y1 == y2)
				break ;
			error += dx;
			y1 += sy;
		}
	}
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
