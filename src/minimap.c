/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 13:43:05 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int	x;
	int	y;

	y = -1;
	cub->minimap = mlx_new_image(cub->mlx, cub->map.x * 3, cub->map.y * 3);
	while (++y < cub->map.x * 3)
	{
		x = -1;
		while (++x < cub->map.y * 3)
		{
			if (cub->map_matrix[x / 3][y / 3] == '0')
				mlx_put_pixel(cub->minimap, y, x, 0xffffff95);
			else if (cub->map_matrix[x / 3][y / 3] != '\n')
				mlx_put_pixel(cub->minimap, y, x, 0x00000095);
		}
	}
	mlx_image_to_window(cub->mlx, cub->minimap, MAP_OFFSET, MAP_OFFSET);
	draw_player_on_minimap(cub);
}

void	draw_player_on_minimap(t_game *cub)
{
	int	x;
	int	y;

	if (cub->miniplayer)
		mlx_delete_image(cub->mlx, cub->miniplayer);
	cub->miniplayer = mlx_new_image(cub->mlx, 3, 3);
	x = -1;
	while (++x < 3)
	{
		y = -1;
		while (++y < 3)
			mlx_put_pixel(cub->miniplayer, y, x, 0xc1121f95);
	}
	mlx_image_to_window(cub->mlx, cub->miniplayer,
		(cub->p1.x * 3) + MAP_OFFSET, (cub->p1.y * 3) + MAP_OFFSET);
	cub->screen->instances->z = 1;
	cub->miniplayer->instances->z = 3;
}
