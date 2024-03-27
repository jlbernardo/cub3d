/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 20:00:24 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	mini_map(cub);
}

void	mini_map(t_game *cub)
{
	draw_player(cub);
}

void	draw_player(t_game *cub)
{
	int	x;
	int	y;

	cub->map.px = 300;
	cub->map.py = 300;
	cub->map.size = 8;
	cub->map.color = 0x21F2FCFF;
	cub->map.player = mlx_new_image(cub->mlx, cub->map.size, cub->map.size);
	x = 0;
	while (x < cub->map.size)
	{
		y = -1;
		while (++y < cub->map.size)
			mlx_put_pixel(cub->map.player, x, y, cub->map.color);
		x++;
	}
	mlx_image_to_window(cub->mlx, cub->map.player, cub->map.px, cub->map.py);
}
