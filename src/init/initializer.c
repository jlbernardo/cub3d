/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/21 21:46:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
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
