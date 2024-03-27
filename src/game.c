/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 20:17:44 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_W))
		cub->map.player->instances->y -= 5;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_S))
		cub->map.player->instances->y += 5;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_A))
		cub->map.player->instances->x -= 5;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_D))
		cub->map.player->instances->x += 5;
}
