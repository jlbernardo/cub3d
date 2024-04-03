/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/03 02:08:06 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	create_matrix(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	cub->p1 = coordinate(4, 4);
	cub->direction = vector(1, 0);
	cub->camera_plane = vector(0, 0.66);
	draw(cub);
}
