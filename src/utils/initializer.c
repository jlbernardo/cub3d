/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/17 20:26:26 by julberna         ###   ########.fr       */
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
	mlx_set_icon(cub->mlx, cub->texture[LOGO]);
	draw_ceiling_floor(cub);
	raycast(cub);
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
	cub->texture[ODL] = mlx_load_png("./assets/odoorl.png");
	cub->texture[ODD] = mlx_load_png("./assets/odoord.png");
	cub->texture[LOGO] = mlx_load_png("./assets/logo.png");
	i = -1;
	while (++i < TOTAL_TEXTURES)
	{
		if (!cub->texture[i])
			cuberror("There was a problem loading the textures.", cub);
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
