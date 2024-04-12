/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/12 15:36:37 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

_Bool	init(t_game *cub)
{
	cub->map_data.raw_data = get_raw_data(cub->map_path);
	load_textures(cub);
	if (!parsing_suite(cub))
		return (false);
	cub->direction = vector(-1, 0);
	cub->camera_plane = vector(0, 0.66);
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	draw_ceiling_floor(cub);
	raycast(cub);
	draw_minimap(cub);
	return (true);
}

void	load_textures(t_game *cub)
{
	cub->texture[NO] = mlx_load_png("assets/brick-1l.png");
	cub->texture[SO] = mlx_load_png("assets/brick-2l.png");
	cub->texture[EA] = mlx_load_png("assets/brick-1d.png");
	cub->texture[WE] = mlx_load_png("assets/brick-2d.png");
}
