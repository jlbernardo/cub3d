/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/01 16:34:17 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_game *cub)
{
	mlx_loop_hook(cub->mlx, draw, cub);
	mlx_loop_hook(cub->mlx, actions, cub);
	mlx_loop(cub->mlx);
}

void	actions(void *param)
{
	t_game	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_S))
	{
		cub->p1.x -= cub->p1.delta_x;
		cub->p1.y -= cub->p1.delta_y;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		cub->p1.x += cub->p1.delta_x;
		cub->p1.y += cub->p1.delta_y;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->p1.angle -= 0.1;
		if (cub->p1.angle < 0)
			cub->p1.angle += 2 * PI;
		cub->p1.delta_x = cos(cub->p1.angle) * 5;
		cub->p1.delta_y = sin(cub->p1.angle) * 5;

	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->p1.angle += 0.1;
		if (cub->p1.angle > 2 * PI)
			cub->p1.angle -= 2 * PI;
		cub->p1.delta_x = cos(cub->p1.angle) * 5;
		cub->p1.delta_y = sin(cub->p1.angle) * 5;
	}
}
