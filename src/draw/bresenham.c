/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:44:30 by julberna          #+#    #+#             */
/*   Updated: 2024/04/17 20:13:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	line(t_game *cub, t_coord start, t_coord end, int buffer[HEIGHT])
{
	t_draw	line;

	algo_setup(&line, start, end);
	while (true)
	{
		if (buffer[line.i] != 0)
			mlx_put_pixel(cub->screen, start.y, start.x, buffer[line.i]);
		line.i++;
		if (start.x == end.x && start.y == end.y)
			break ;
		if (line.error * 2 >= -line.delta_y)
		{
			if (start.x == end.x)
				break ;
			line.error -= line.delta_y;
			start.x += line.step_x;
		}
		if (line.error * 2 <= line.delta_x)
		{
			if (start.y == end.y)
				break ;
			line.error += line.delta_x;
			start.y += line.step_y;
		}
	}
}

void	algo_setup(t_draw *line, t_coord start, t_coord end)
{
	line->i = (int)start.x;
	line->step_x = 1;
	line->step_y = 1;
	line->delta_x = fabs(end.x - start.x);
	line->delta_y = fabs(end.y - start.y);
	if (start.x > end.x)
		line->step_x = -1;
	if (start.y > end.y)
		line->step_y = -1;
	line->error = line->delta_x - line->delta_y;
}
