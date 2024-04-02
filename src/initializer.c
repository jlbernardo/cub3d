/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/01 21:04:47 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	create_matrix(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	cub->p1.x = 300;
	cub->p1.y = 300;
	cub->p1.angle = (float)PI;
	cub->p1.delta_x = cos(cub->p1.angle) * 5;
	cub->p1.delta_y = sin(cub->p1.angle) * 5;
	draw(cub);
}
