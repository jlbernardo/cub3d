/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/17 15:54:17 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int			x;
	int			y;
	const int	rx = ceil(WIDTH / RATIO);
	const int	ry = ceil(HEIGHT / RATIO);

	y = -1;
	cub->minimap = mlx_new_image(cub->mlx, cub->map.x * ry, cub->map.y * rx);
	if (!cub->minimap)
		cuberror("Oops, we had a problem with the minimap. ˙◠˙", cub);
	while (++y < cub->map.y * rx)
	{
		x = 0;
		while (x < (int)(ft_strlen(cub->map_matrix[(int)(y / rx)]) * ry))
		{
			if (cub->map_matrix[(int)(y / rx)][(int)(x / ry)] == '1'
				|| cub->map_matrix[(int)(y / rx)][(int)(x / ry)] == '2')
				mlx_put_pixel(cub->minimap, x, y, 0x00000095);
			else if (cub->map_matrix[(int)(y / rx)][(int)(x / ry)] != ' ')
				mlx_put_pixel(cub->minimap, x, y, 0xffffff95);
			x++;
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
	while (++x < rx)
	{
		y = -1;
		while (++y < ry)
			mlx_put_pixel(cub->miniplayer, x, y, 0xc1121f95);
	}
	mlx_image_to_window(cub->mlx, cub->miniplayer,
		cub->p1.x * ry + MAP_OFFSET - (int)(ry / 3),
		cub->p1.y * rx + MAP_OFFSET - (int)(rx / 3));
	cub->screen->instances->z = 1;
	cub->miniplayer->instances->z = 3;
}
