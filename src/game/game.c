/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/17 16:34:17 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	game(t_game *cub)
{
	mlx_loop_hook(cub->mlx, actions, cub);
	mlx_loop_hook(cub->mlx, mouse_control, cub);
	mlx_loop(cub->mlx);
}

void	actions(void *param)
{
	t_game	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		over(cub, EXIT_SUCCESS);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_S))
		walk_back(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_W))
		walk_forward(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		walk_sideways(cub, MLX_KEY_A);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		walk_sideways(cub, MLX_KEY_D);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		rotate_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		rotate_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_SPACE))
		open_door(cub);
	raycast(cub);
	draw_minimap(cub);
}
