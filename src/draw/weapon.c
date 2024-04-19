/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:03:34 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/19 18:30:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_weapon(t_game *cub, bool reload, int i)
{
	static int	j;

	j += i;
	if (reload && j == 15)
	{
		j = 0;
		cub->weapon_img_layer[14]->enabled = false;
		cub->weapon_img_layer[j]->enabled = true;
		cub->weapon_reloading = false;
	}
	else if (!reload)
	{
		cub->weapon_img_layer[j]->enabled = true;
		cub->weapon_reloading = false;
		cub->last_fps = mlx_get_time();
	}
	else
	{
		cub->weapon_img_layer[j - 1]->enabled = false;
		cub->weapon_img_layer[j]->enabled = true;
		cub->weapon_reloading = true;
	}
}
