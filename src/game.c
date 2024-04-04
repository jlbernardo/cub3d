/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/03 22:30:44 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_game *cub)
{
	mlx_loop_hook(cub->mlx, raycast, cub);
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
		walk_front(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_D))
		rotate_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_A))
		rotate_left(cub);
}
