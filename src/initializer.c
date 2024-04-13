/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/12 21:07:32 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

_Bool	init(t_game *cub)
{
	cub->map_data.raw_data = get_raw_data(cub->map_path);
	if (!parsing_suite(cub))
		return (false);
	if (!validation_suite(cub))
		return (false);
	load_textures(cub);
	cub->direction = vector(1, 0);                                          // -1, 0            0, -1             0, 1           1, 0
	cub->camera_plane = vector(0, -0.66);									 // 0, 0.66          -0.66, 0         0.66, 0        0, -0.66
	cub->rotation_speed = 0.02;												 //WE	             //SO             //NO           //EA
	cub->move_speed = 0.06;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	draw_ceiling_floor(cub);
	raycast(cub);
	// draw_minimap(cub);
	return (true);
}

void	load_textures(t_game *cub)
{
	cub->texture[NO] = mlx_load_png(cub->map_data.north_tex_path);
	cub->texture[SO] = mlx_load_png(cub->map_data.south_tex_path);
	cub->texture[EA] = mlx_load_png(cub->map_data.east_tex_path);
	cub->texture[WE] = mlx_load_png(cub->map_data.west_tex_path);
}
