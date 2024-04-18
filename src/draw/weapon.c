/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:03:34 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/17 21:51:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	draw_weapon(t_game *cub, bool reload)
{
	int i;
	
	i = 1;
	if (reload == false)
	{
		if (cub->weapon_layer[14])
			mlx_delete_image(cub->mlx, cub->weapon_layer[14]);
		cub->weapon_layer[0] = mlx_texture_to_image(cub->mlx, cub->weapon[0]);
		mlx_image_to_window(cub->mlx, 
		cub->weapon_layer[0], WIDTH / 2 - cub->weapon[0]->width / 2,
		HEIGHT - cub->weapon[0]->height);
		cub->weapon_layer[0]->instances->z = 4;
	}
	else if (reload == true)
	{
		while (i < 15)
		{
			mlx_delete_image(cub->mlx, cub->weapon_layer[i - 1]);
			cub->weapon_layer[i] = mlx_texture_to_image(cub->mlx, cub->weapon[i]);
			mlx_image_to_window(cub->mlx, 
			cub->weapon_layer[i], WIDTH / 2 - cub->weapon[i]->width / 2,
			HEIGHT - cub->weapon[i]->height);
			cub->weapon_layer[i]->instances->z = 4;
			i++;
			usleep(10000);
			printf("AAAAAAAAAAAAA\n");
		}
		draw_weapon(cub, false);
	}	
}
