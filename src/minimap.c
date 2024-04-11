/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/10 21:12:56 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int			x;
	int			y;

	y = -1;
	cub->minimap = mlx_new_image(cub->mlx,
			(int)(WIDTH / RATIO), (int)(HEIGHT / RATIO));
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
	int			i;
	int			j;
	const int	size_x = cub->minimap->width / cub->map.x;
	const int	size_y = cub->minimap->height / cub->map.y;

	i = (x * size_x) - 1;
	while (++i < (x * size_x) + size_x)
	{
		j = (y * size_y) - 1;
		while (++j < (y * size_y) + size_y)
			mlx_put_pixel(cub->minimap, j, i, color);
	}
}

// while (i < width)
// {
// 	j = -1;
// 	while (++j < height)
// 	{
// 		if (i <= 2 || i >= (width - 3) || j <= 2 || j >= (height - 3))
// 			color = 0x000000ff;
// 		else
// 			color = 0xffffffff;
// 		mlx_put_pixel(cub->minimap, i, j, color);
// 	}
// 	i++;
// }
