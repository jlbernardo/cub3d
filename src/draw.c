/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:13:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/01 14:38:19 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(void *param)
{
	t_game	*cub;

	cub = param;
	mlx_delete_image(cub->mlx, cub->gen);
	cub->gen = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	draw_matrix(cub);
	draw_player(cub);
	raycast(cub);
	mlx_image_to_window(cub->mlx, cub->gen, 0, 0);
}

void	draw_player(t_game *cub)
{
	int	x;
	int	y;

	x = -4;
	while (x < 5)
	{
		y = -5;
		while (++y < 5)
			mlx_put_pixel(cub->gen, cub->p1.y + y, cub->p1.x + x, 0x21F2FCFF);
		x++;
	}
}

void	draw_matrix(t_game *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < cub->map.x)
	{
		y = -1;
		while (++y < cub->map.y)
		{
			if (cub->map.matrix[y][x] == '1')
				draw_block(cub, x * SIZE, y * SIZE, 0xFFFFFFFF);
			else if (cub->map.matrix[y][x] == '0')
				draw_block(cub, x * SIZE, y * SIZE, 0x000000FF);
		}
		x++;
	}
}

void	draw_block(t_game *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE - 1)
	{
		j = -1;
		while (++j < SIZE - 1)
			mlx_put_pixel(cub->gen, x + i, y + j, color);
		i++;
	}
}
