/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:16 by julberna          #+#    #+#             */
/*   Updated: 2024/04/21 22:10:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_screen(t_game *cub)
{
	draw_background(cub);
	raycast(cub);
	draw_minimap(cub);
	draw_weapon(cub, false, 0);
}

void	draw_background(t_game *cub)
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
	cub->ceiling_floor->instances->z = 0;
}

void	draw_weapon(t_game *cub, bool reload, int i)
{
	static int	j;

	j += i;
	if (reload && j == WEAPON_FRAMES)
	{
		j = 0;
		cub->weapon[WEAPON_FRAMES - 1]->enabled = false;
		cub->weapon[j]->enabled = true;
		cub->weapon_reloading = false;
	}
	else if (!reload)
	{
		cub->weapon[j]->enabled = true;
		cub->weapon_reloading = false;
		cub->last_fps = mlx_get_time();
	}
	else
	{
		cub->weapon[j - 1]->enabled = false;
		cub->weapon[j]->enabled = true;
		cub->weapon_reloading = true;
	}
}
