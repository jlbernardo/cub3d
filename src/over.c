/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/04 19:06:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	over(t_game *cub)
{
	int	i;

	i = -1;
	mlx_delete_image(cub->mlx, cub->screen);
	mlx_delete_image(cub->mlx, cub->ceiling_floor);
	while (++i < cub->map.y)
		free(cub->map_matrix[i]);
	free(cub->map_matrix);
	mlx_terminate(cub->mlx);
}
