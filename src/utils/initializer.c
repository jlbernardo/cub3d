/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/21 19:00:58 by julberna         ###   ########.fr       */
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
	mlx_set_icon(cub->mlx, cub->texture[LOGO]);
	mlx_set_mouse_pos(cub->mlx, WIDTH / HORIZON, HEIGHT / HORIZON);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	draw_ceiling_floor(cub);
	raycast(cub);
	create_weapon_imgs(cub);
	draw_weapon(cub, false, 0);
	draw_minimap(cub);
}

void	load_textures(t_game *cub)
{
	int	i;

	cub->texture[NO] = mlx_load_png(cub->map_data.north_tex_path);
	cub->texture[EA] = mlx_load_png(cub->map_data.east_tex_path);
	cub->texture[SO] = mlx_load_png(cub->map_data.south_tex_path);
	cub->texture[WE] = mlx_load_png(cub->map_data.west_tex_path);
	cub->texture[CDL] = mlx_load_png("./assets/cdoorl.png");
	cub->texture[CDD] = mlx_load_png("./assets/cdoord.png");
	cub->texture[LDL] = mlx_load_png("./assets/ldoorl.png");
	cub->texture[LDD] = mlx_load_png("./assets/ldoord.png");
	cub->texture[RDL] = mlx_load_png("./assets/rdoorl.png");
	cub->texture[RDD] = mlx_load_png("./assets/rdoord.png");
	cub->texture[LOGO] = mlx_load_png("./assets/logo.png");
	i = -1;
	while (++i < TOTAL_TEXTURES)
	{
		if (!cub->texture[i])
			cuberror("There was a problem loading the textures.", cub);
	}
}

void	create_weapon_imgs(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		cub->weapon[i] = mlx_texture_to_image(
				cub->mlx, cub->weapon_t[i]);
		cub->weapon[i]->enabled = false;
		mlx_image_to_window(cub->mlx, cub->weapon[i], WIDTH / 2,
			HEIGHT - cub->weapon_t[i]->height);
	}
}

void	load_weapon_textures(t_game *cub)
{
	int	i;

	i = -1;
	cub->weapon_t[0] = mlx_load_png("assets/doom_weapons_1.png");
	cub->weapon_t[1] = mlx_load_png("assets/doom_weapons_2.png");
	cub->weapon_t[2] = mlx_load_png("assets/doom_weapons_3.png");
	cub->weapon_t[3] = mlx_load_png("assets/doom_weapons_4.png");
	cub->weapon_t[4] = mlx_load_png("assets/doom_weapons_5.png");
	cub->weapon_t[5] = mlx_load_png("assets/doom_weapons_6.png");
	cub->weapon_t[6] = mlx_load_png("assets/doom_weapons_7.png");
	cub->weapon_t[7] = mlx_load_png("assets/doom_weapons_8.png");
	cub->weapon_t[8] = mlx_load_png("assets/doom_weapons_9.png");
	cub->weapon_t[9] = mlx_load_png("assets/doom_weapons_10.png");
	cub->weapon_t[10] = mlx_load_png("assets/doom_weapons_11.png");
	cub->weapon_t[11] = mlx_load_png("assets/doom_weapons_12.png");
	cub->weapon_t[12] = mlx_load_png("assets/doom_weapons_13.png");
	cub->weapon_t[13] = mlx_load_png("assets/doom_weapons_14.png");
	cub->weapon_t[14] = mlx_load_png("assets/doom_weapons_15.png");
	while (++i < 15)
	{
		if (!cub->weapon_t[i])
			cuberror("There was a problem loading the weapon.", cub);
	}
}

void	draw_ceiling_floor(t_game *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub->ceiling_floor = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->ceiling_floor)
		cuberror("Oops, had a problem with the background. ˙◠˙", cub);
	while (x < HEIGHT)
	{
		while (y < WIDTH)
		{
			if (x < (int)(HEIGHT / HORIZON))
				mlx_put_pixel(cub->ceiling_floor, y, x, cub->map_data.c_color);
			else
				mlx_put_pixel(cub->ceiling_floor, y, x, cub->map_data.f_color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(cub->mlx, cub->ceiling_floor, 0, 0);
}
