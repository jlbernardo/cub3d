/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:44:30 by julberna          #+#    #+#             */
/*   Updated: 2024/04/01 19:39:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		absolute(int num);
void	algo_setup(t_draw *line, int point_a[X_AND_Y], int point_b[X_AND_Y]);

void	line(t_game *cub, int point_a[X_AND_Y], int point_b[X_AND_Y])
{
	t_draw	line;

	algo_setup(&line, point_a, point_b);
	while (true)
	{
		mlx_put_pixel(cub->gen, point_a[Y], point_a[X], 0x21F2FCFF);
		if (point_a[X] == point_b[X] && point_a[Y] == point_b[Y])
			break ;
		if (line.error * 2 >= -line.dy)
		{
			if (point_a[X] == point_b[X])
				break ;
			line.error -= line.dy;
			point_a[X] += line.sx;
		}
		if (line.error * 2 <= line.dx)
		{
			if (point_a[Y] == point_b[Y])
				break ;
			line.error += line.dx;
			point_a[Y] += line.sy;
		}
	}
}

void	algo_setup(t_draw *line, int point_a[X_AND_Y], int point_b[X_AND_Y])
{
	line->sx = 1;
	line->sy = 1;
	line->dx = absolute(point_b[X] - point_a[X]);
	line->dy = absolute(point_b[Y] - point_a[Y]);
	if (point_a[X] > point_b[X])
		line->sx = -1;
	if (point_a[Y] > point_b[Y])
		line->sy = -1;
	line->error = line->dx - line->dy;
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
