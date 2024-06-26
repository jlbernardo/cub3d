/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:29:12 by julberna          #+#    #+#             */
/*   Updated: 2024/04/21 22:15:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_forward(t_game *cub)
{
	const int	x1 = (int)(cub->p1.x + cub->direction.x * cub->move_speed);
	const int	y1 = (int)cub->p1.y;
	const int	x2 = (int)cub->p1.x;
	const int	y2 = (int)(cub->p1.y + cub->direction.y * cub->move_speed);

	if (cub->map_matrix[y1][x1] != '1' && cub->map_matrix[y1][x1] != '2')
		cub->p1.x += cub->direction.x * cub->move_speed;
	if (cub->map_matrix[y2][x2] != '1' && cub->map_matrix[y2][x2] != '2')
		cub->p1.y += cub->direction.y * cub->move_speed;
}

void	walk_backward(t_game *cub)
{
	const int	x1 = (int)(cub->p1.x - cub->direction.x * cub->move_speed);
	const int	y1 = (int)cub->p1.y;
	const int	x2 = (int)cub->p1.x;
	const int	y2 = (int)(cub->p1.y - cub->direction.y * cub->move_speed);

	if (cub->map_matrix[y1][x1] != '1' && cub->map_matrix[y1][x1] != '2')
		cub->p1.x -= cub->direction.x * cub->move_speed;
	if (cub->map_matrix[y2][x2] != '1' && cub->map_matrix[y2][x2] != '2')
		cub->p1.y -= cub->direction.y * cub->move_speed;
}

void	rotate_right(t_game *cub)
{
	double	old_dir;
	double	old_plane_x;

	old_dir = cub->direction.x;
	old_plane_x = cub->camera_plane.x;
	cub->direction.x = cub->direction.x * cos(cub->rotation_speed)
		- cub->direction.y * sin(cub->rotation_speed);
	cub->direction.y = old_dir * sin(cub->rotation_speed)
		+ cub->direction.y * cos(cub->rotation_speed);
	cub->camera_plane.x = cub->camera_plane.x * cos(cub->rotation_speed)
		- cub->camera_plane.y * sin(cub->rotation_speed);
	cub->camera_plane.y = old_plane_x * sin(cub->rotation_speed)
		+ cub->camera_plane.y * cos(cub->rotation_speed);
}

void	rotate_left(t_game *cub)
{
	double	old_dir;
	double	old_plane_x;

	old_dir = cub->direction.x;
	old_plane_x = cub->camera_plane.x;
	cub->direction.x = cub->direction.x * cos(-cub->rotation_speed)
		- cub->direction.y * sin(-cub->rotation_speed);
	cub->direction.y = old_dir * sin(-cub->rotation_speed)
		+ cub->direction.y * cos(-cub->rotation_speed);
	cub->camera_plane.x = cub->camera_plane.x * cos(-cub->rotation_speed)
		- cub->camera_plane.y * sin(-cub->rotation_speed);
	cub->camera_plane.y = old_plane_x * sin(-cub->rotation_speed)
		+ cub->camera_plane.y * cos(-cub->rotation_speed);
}

void	walk_sideways(t_game *cub, int key)
{
	const int	x1 = (int)(cub->p1.x + cub->direction.y * cub->move_speed);
	const int	y1 = (int)(cub->p1.y - cub->direction.x * cub->move_speed);
	const int	x2 = (int)(cub->p1.x - cub->direction.y * cub->move_speed);
	const int	y2 = (int)(cub->p1.y + cub->direction.x * cub->move_speed);

	if (key == MLX_KEY_A
		&& (cub->map_matrix[y1][x1] != '1' && cub->map_matrix[y1][x1] != '2'))
	{
		cub->p1.x += cub->direction.y * cub->move_speed;
		cub->p1.y -= cub->direction.x * cub->move_speed;
	}
	if (key == MLX_KEY_D
		&& (cub->map_matrix[y2][x2] != '1' && cub->map_matrix[y2][x2] != '2'))
	{
		cub->p1.x -= cub->direction.y * cub->move_speed;
		cub->p1.y += cub->direction.x * cub->move_speed;
	}
}
