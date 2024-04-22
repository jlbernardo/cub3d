/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:05:08 by julberna          #+#    #+#             */
/*   Updated: 2024/04/21 21:39:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *cub)
{
	int	i;

	cub->texture[NO] = mlx_load_png(cub->map_data.north_tex_path);
	cub->texture[EA] = mlx_load_png(cub->map_data.east_tex_path);
	cub->texture[SO] = mlx_load_png(cub->map_data.south_tex_path);
	cub->texture[WE] = mlx_load_png(cub->map_data.west_tex_path);
	cub->texture[CDL] = mlx_load_png("./assets/door/cdoorl.png");
	cub->texture[CDD] = mlx_load_png("./assets/door/cdoord.png");
	cub->texture[LDL] = mlx_load_png("./assets/door/ldoorl.png");
	cub->texture[LDD] = mlx_load_png("./assets/door/ldoord.png");
	cub->texture[RDL] = mlx_load_png("./assets/door/rdoorl.png");
	cub->texture[RDD] = mlx_load_png("./assets/door/rdoord.png");
	cub->texture[LOGO] = mlx_load_png("./assets/logo.png");
	i = -1;
	while (++i < TOTAL_TEXTURES)
	{
		if (!cub->texture[i])
			cuberror("There was a problem loading the textures.", cub);
	}
	load_weapon_textures(cub);
}

void	load_weapon_textures(t_game *cub)
{
	int	i;

	i = -1;
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_1.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_2.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_3.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_4.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_5.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_6.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_7.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_8.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_9.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_10.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_11.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_12.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_13.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_14.png");
	cub->weapon_t[++i] = mlx_load_png("assets/weapon/doom_weapons_15.png");
	i = -1;
	while (++i < WEAPON_FRAMES)
	{
		if (!cub->weapon_t[i])
			cuberror("There was a problem loading the weapon textures.", cub);
	}
	load_weapon_images(cub);
}

void	load_weapon_images(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < WEAPON_FRAMES)
	{
		cub->weapon[i] = mlx_texture_to_image(cub->mlx, cub->weapon_t[i]);
		if (!cub->weapon[i])
			cuberror("There was a problem loading the weapon images.", cub);
		cub->weapon[i]->enabled = false;
		mlx_image_to_window(cub->mlx, cub->weapon[i], WIDTH / 2,
			HEIGHT - cub->weapon_t[i]->height);
		cub->weapon[i]->instances->z = i + 4;
	}
}
