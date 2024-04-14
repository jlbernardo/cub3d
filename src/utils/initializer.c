/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/14 17:58:29 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	load_textures(cub);
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	if (!cub->mlx)
		cuberror("There was a problem opening the window.", cub);
	mlx_set_icon(cub->mlx, cub->logo);
	draw_ceiling_floor(cub);
	raycast(cub);
	draw_minimap(cub);
}

void	load_textures(t_game *cub)
{
	cub->texture[EA] = mlx_load_png(cub->map_data.east_tex_path);
	cub->texture[WE] = mlx_load_png(cub->map_data.west_tex_path);
	cub->texture[NO] = mlx_load_png(cub->map_data.north_tex_path);
	cub->texture[SO] = mlx_load_png(cub->map_data.south_tex_path);
	cub->logo = mlx_load_png("./assets/logo.png");
	cub->door = mlx_load_png("./assets/door.png");
	if (!cub->texture[EA] || !cub->texture[WE]
		|| !cub->texture[NO] || !cub->texture[SO]
		|| !cub->logo || !cub->door)
		cuberror("There was a problem loading the textures.", cub);
}
