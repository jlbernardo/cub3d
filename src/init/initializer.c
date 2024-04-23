/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/22 20:35:41 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "/ᐠ - ˕ -マ game on!", false);
	if (!cub->mlx)
		cuberror("There was a problem opening the window.", cub);
	cub->time = mlx_get_time();
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	load_textures(cub);
	mlx_set_icon(cub->mlx, cub->texture[LOGO]);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cub->mlx, WIDTH / HORIZON, HEIGHT / HORIZON);
	draw_screen(cub);
}
