/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:03:34 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 19:00:58 by julberna         ###   ########.fr       */
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
		cub->weapon[14]->enabled = false;
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
