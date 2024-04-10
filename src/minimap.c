/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:00:41 by julberna          #+#    #+#             */
/*   Updated: 2024/04/10 18:52:46 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *cub)
{
	int			i;
	int			j;
	int			color;
	const int	width = (int)(WIDTH / RATIO);
	const int	height = (int)(HEIGHT / RATIO);

	i = 0;
	cub->minimap = mlx_new_image(cub->mlx, width, height);
	while (i < width)
	{
		j = -1;
		while (++j < height)
		{
			if (i <= 2 || i >= (width - 3) || j <= 2 || j >= (height - 3))
				color = 0x000000ff;
			else
				color = 0xffffffff;
			mlx_put_pixel(cub->minimap, i, j, color);
		}
		i++;
	}
	mlx_image_to_window(cub->mlx, cub->minimap, 10, 10);
}
