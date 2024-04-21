/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/21 00:05:36 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	load_textures(cub);
	load_weapon_textures(cub);
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	if (!cub->mlx)
		cuberror("There was a problem opening the window.", cub);
	cub->time = mlx_get_time();
	mlx_set_icon(cub->mlx, cub->logo);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	draw_ceiling_floor(cub);
	raycast(cub);
	create_weapon_imgs(cub);
	draw_weapon(cub, false, 0);
	draw_minimap(cub);
}

void	load_textures(t_game *cub)
{
	cub->texture[EA] = mlx_load_png(cub->map_data.east_tex_path);
	cub->texture[WE] = mlx_load_png(cub->map_data.west_tex_path);
	cub->texture[NO] = mlx_load_png(cub->map_data.north_tex_path);
	cub->texture[SO] = mlx_load_png(cub->map_data.south_tex_path);
	cub->logo = mlx_load_png("./assets/logo.png");
	if (!cub->texture[EA] || !cub->texture[WE]
		|| !cub->texture[NO] || !cub->texture[SO]
		|| !cub->logo)
		cuberror("There was a problem loading the textures.", cub);
}

void	create_weapon_imgs(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		cub->weapon_img_layer[i] = mlx_texture_to_image(
				cub->mlx, cub->weapon_texture[i]);
		cub->weapon_img_layer[i]->enabled = false;
		mlx_image_to_window(cub->mlx, cub->weapon_img_layer[i], WIDTH / 2,
			HEIGHT - cub->weapon_texture[i]->height);
	}
}

void	load_weapon_textures(t_game *cub)
{
	int	i;

	i = -1;
	cub->weapon_texture[0] = mlx_load_png("assets/doom_weapons_1.png");
	cub->weapon_texture[1] = mlx_load_png("assets/doom_weapons_2.png");
	cub->weapon_texture[2] = mlx_load_png("assets/doom_weapons_3.png");
	cub->weapon_texture[3] = mlx_load_png("assets/doom_weapons_4.png");
	cub->weapon_texture[4] = mlx_load_png("assets/doom_weapons_5.png");
	cub->weapon_texture[5] = mlx_load_png("assets/doom_weapons_6.png");
	cub->weapon_texture[6] = mlx_load_png("assets/doom_weapons_7.png");
	cub->weapon_texture[7] = mlx_load_png("assets/doom_weapons_8.png");
	cub->weapon_texture[8] = mlx_load_png("assets/doom_weapons_9.png");
	cub->weapon_texture[9] = mlx_load_png("assets/doom_weapons_10.png");
	cub->weapon_texture[10] = mlx_load_png("assets/doom_weapons_11.png");
	cub->weapon_texture[11] = mlx_load_png("assets/doom_weapons_12.png");
	cub->weapon_texture[12] = mlx_load_png("assets/doom_weapons_13.png");
	cub->weapon_texture[13] = mlx_load_png("assets/doom_weapons_14.png");
	cub->weapon_texture[14] = mlx_load_png("assets/doom_weapons_15.png");
	while (++i < 15)
	{
		if (!cub->weapon_texture[i])
			cuberror("There was a problem loading the weapon.", cub);
	}
}
