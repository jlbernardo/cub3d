/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/04 20:36:25 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	game(t_game *cub)
{
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
		walk_back(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_W))
		walk_forward(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_D))
		rotate_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_A))
		rotate_left(cub);
	raycast(cub);
}
