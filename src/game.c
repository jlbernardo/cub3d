/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:01:10 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/03 16:00:03 by julberna         ###   ########.fr       */
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
		cub->p1.x -= cub->ray.dir.x * cub->move_speed;
		cub->p1.y -= cub->ray.dir.y * cub->move_speed;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		cub->p1.x += cub->ray.dir.x * cub->move_speed;
		cub->p1.y += cub->ray.dir.y * cub->move_speed;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_D))
		rotate_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub->mlx, MLX_KEY_A))
		;
}

void	rotate_right(t_game *cub)
{
	double	old_dir;
	double	old_plane_x;

	old_dir = cub->ray.dir.x;
	old_plane_x = cub->camera_plane.x;
	cub->ray.dir.x = cub->ray.dir.x * cos(-cub->rotation_speed)
		- cub->ray.dir.y * sin(-cub->rotation_speed);
	cub->ray.dir.y = old_dir * sin(-cub->rotation_speed)
		+ cub->ray.dir.y * cos(-cub->rotation_speed);
	cub->camera_plane.x = cub->camera_plane.x * cos(-cub->rotation_speed)
		- cub->camera_plane.y * sin(-cub->rotation_speed);
	cub->camera_plane.y = old_plane_x * sin(-cub->rotation_speed)
		+ cub->camera_plane.y * cos(-cub->rotation_speed);
}
