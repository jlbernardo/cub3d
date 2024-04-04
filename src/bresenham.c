/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:44:30 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 20:55:13 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	algo_setup(t_draw *line, t_coord start, t_coord end);

void	line(t_game *cub, t_coord start, t_coord end, int color)
{
	t_draw	line;

	algo_setup(&line, start, end);
	while (true)
	{
		if(start.x < 0 || start.y < 0)
			return ;
		mlx_put_pixel(cub->gen, start.y, start.x, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		if (line.error * 2 >= -line.dy)
		{
			if (start.x == end.x)
				break ;
			line.error -= line.dy;
			start.x += line.sx;
		}
		if (line.error * 2 <= line.dx)
		{
			if (start.y == end.y)
				break ;
			line.error += line.dx;
			start.y += line.sy;
		}
	}
}

void	algo_setup(t_draw *line, t_coord start, t_coord end)
{
	line->sx = 1;
	line->sy = 1;
	line->dx = fabs(end.x - start.x);
	line->dy = fabs(end.y - start.y);
	if (start.x > end.x)
		line->sx = -1;
	if (start.y > end.y)
		line->sy = -1;
	line->error = line->dx - line->dy;
}
