/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 21:54:10 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	create_matrix(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	draw_matrix(cub);
	draw_player(cub);
}

void	draw_player(t_game *cub)
{
	cub->map.px = 300;
	cub->map.py = 300;
	cub->map.size = 8;
	cub->map.player = mlx_new_image(cub->mlx, cub->map.size, cub->map.size);
	color_block(cub->map.player, 0x21F2FCFF);
	mlx_image_to_window(cub->mlx, cub->map.player, cub->map.px, cub->map.py);
}

void	draw_matrix(t_game *cub)
{
	int	x;
	int	y;

	cub->map.floor = mlx_new_image(cub->mlx, SIZE, SIZE);
	cub->map.wall = mlx_new_image(cub->mlx, SIZE, SIZE);
	color_block(cub->map.floor, 0x000000FF);
	color_block(cub->map.wall, 0xFFFFFFFF);
	x = 0;
	while (x < cub->map.mx)
	{
		y = -1;
		while (++y < cub->map.my)
		{
			if (cub->map.matrix[y][x] == '1')
				mlx_image_to_window(cub->mlx,
					cub->map.wall, x * SIZE, y * SIZE);
			else if (cub->map.matrix[y][x] == '0')
				mlx_image_to_window(cub->mlx,
					cub->map.floor, x * SIZE, y * SIZE);
		}
		x++;
	}
}
