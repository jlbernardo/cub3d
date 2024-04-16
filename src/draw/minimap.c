/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 20:44:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int	x;
	int	y;
	int	rx;
	int	ry;

	y = -1;
	rx = ceil(WIDTH / RATIO);
	ry = ceil(HEIGHT / RATIO);
	cub->minimap = mlx_new_image(cub->mlx, cub->map.x * rx, cub->map.y * ry);
	if (!cub->minimap)
		cuberror("Oops, we had a problem with the minimap. ˙◠˙", cub);
	while (++y < cub->map.x * rx)
	{
		x = -1;
		while (++x < cub->map.y * ry)
		{
			if (cub->map_matrix[(int)(x / ry)][(int)(y / rx)] == '0')
				mlx_put_pixel(cub->minimap, y, x, 0xffffff95);
			else if (cub->map_matrix[(int)(x / ry)][(int)(y / rx)] != '\n')
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
	int	rx;
	int	ry;

	rx = ceil(WIDTH / RATIO);
	ry = ceil(HEIGHT / RATIO);
	if (cub->miniplayer)
		mlx_delete_image(cub->mlx, cub->miniplayer);
	cub->miniplayer = mlx_new_image(cub->mlx, rx, ry);
	if (!cub->miniplayer)
		cuberror("Oops, found an issue on the minimap. ˙◠˙", cub);
	x = -1;
	while (++x < ry)
	{
		y = -1;
		while (++y < rx)
			mlx_put_pixel(cub->miniplayer, y, x, 0xc1121f95);
	}
	mlx_image_to_window(cub->mlx, cub->miniplayer,
		cub->p1.x * rx + MAP_OFFSET - (int)(rx / 3),
		cub->p1.y * ry + MAP_OFFSET - (int)(rx / 3));
	cub->screen->instances->z = 1;
	cub->miniplayer->instances->z = 3;
}
