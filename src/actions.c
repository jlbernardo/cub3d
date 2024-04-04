/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:29:12 by julberna          #+#    #+#             */
/*   Updated: 2024/04/03 22:34:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_front(t_game *cub)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (int)(cub->p1.x - cub->ray.dir.x * cub->move_speed);
	y1 = (int)cub->p1.y;
	x2 = (int)cub->p1.x;
	y2 = (int)(cub->p1.y - cub->ray.dir.y * cub->move_speed);
	if (cub->map_matrix[x1][y1] == '0' && cub->map_matrix[x2][y2] == '0')
	{
		cub->p1.x += cub->ray.dir.x * cub->move_speed;
		cub->p1.y += cub->ray.dir.y * cub->move_speed;
	}
}

void	walk_back(t_game *cub)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (int)(cub->p1.x - cub->ray.dir.x * cub->move_speed);
	y1 = (int)cub->p1.y;
	x2 = (int)cub->p1.x;
	y2 = (int)(cub->p1.y - cub->ray.dir.y * cub->move_speed);
	if (cub->map_matrix[x1][y1] == '0' && cub->map_matrix[x2][y2] == '0')
	{
		cub->p1.x -= cub->ray.dir.x * cub->move_speed;
		cub->p1.y -= cub->ray.dir.y * cub->move_speed;
	}
}

void	rotate_right(t_game *cub)
{
	double	old_dir;
	double	old_plane_x;

	old_dir = cub->ray.dir.x;
	old_plane_x = cub->camera_plane.x;
	cub->ray.dir.x = cub->ray.dir.x * cos(cub->rotation_speed)
		- cub->ray.dir.y * sin(cub->rotation_speed);
	cub->ray.dir.y = old_dir * sin(cub->rotation_speed)
		+ cub->ray.dir.y * cos(cub->rotation_speed);
	cub->camera_plane.x = cub->camera_plane.x * cos(cub->rotation_speed)
		- cub->camera_plane.y * sin(cub->rotation_speed);
	cub->camera_plane.y = old_plane_x * sin(cub->rotation_speed)
		+ cub->camera_plane.y * cos(cub->rotation_speed);
}

void	rotate_left(t_game *cub)
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
