/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/11 00:11:15 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int	x;
	int	y;
	int	size;

	y = -1;
	if (WIDTH < HEIGHT)
		size = (int)(WIDTH / RATIO);
	else
		size = (int)(HEIGHT / RATIO);
	cub->minimap = mlx_new_image(cub->mlx, size, size);
	while (++y < cub->map.x)
	{
		x = -1;
		while (++x < cub->map.y)
		{
			if (cub->map_matrix[x][y] == '0')
				put_square(cub, x, y, 0xffffffff);
			else if (cub->map_matrix[x][y] != '\n')
				put_square(cub, x, y, 0x000000ff);
		}
	}
	mlx_image_to_window(cub->mlx, cub->minimap, 10, 10);
}

void	put_square(t_game *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	if (cub->map.x > cub->map.y)
		size = cub->minimap->width / cub->map.x;
	else
		size = cub->minimap->width / cub->map.y;
	i = (x * size) - 1;
	while (++i < (x * size) + size)
	{
		j = (y * size) - 1;
		while (++j < (y * size) + size)
			mlx_put_pixel(cub->minimap, j, i, color);
	}
	cub->mini_size.y = i + 9;
	cub->mini_size.x = j + 9;
}
