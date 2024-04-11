/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/11 01:27:29 by julberna         ###   ########.fr       */
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
	mlx_image_to_window(cub->mlx, cub->minimap, MAP_OFFSET, MAP_OFFSET);
	draw_player_on_minimap(cub);
}

void	draw_player_on_minimap(t_game *cub)
{
	int	i;
	int	j;
	int	size_x;
	int	size_y;

	size_x = (cub->mini_size.x / cub->map.x);
	size_y = (cub->mini_size.y / cub->map.y);
	mlx_delete_image(cub->mlx, cub->miniplayer);
	cub->miniplayer = mlx_new_image(cub->mlx, size_x, size_y);
	i = -1;
	while (++i < size_x)
	{
		j = -1;
		while (++j < size_y)
			mlx_put_pixel(cub->miniplayer, j, i, 0xc1121fff);
	}
	mlx_image_to_window(cub->mlx, cub->miniplayer,
		cub->p1.x * (cub->mini_size.x / cub->map.x) + size_x,
		cub->p1.y * (cub->mini_size.y / cub->map.y) + size_y);
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
	cub->mini_size.y = i + MAP_OFFSET - 1;
	cub->mini_size.x = j + MAP_OFFSET - 1;
}
