/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/08 21:18:15 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

_Bool	init(t_game *cub)
{
	cub->map_data.raw_data = get_raw_data(cub->map_path);
	if(!parsing_suite(cub))
		return (false);
	cub->direction = vector(-1, 0);
	cub->camera_plane = vector(0, 0.66);
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	draw_ceiling_floor(cub);
	raycast(cub);
	return (true);
}
