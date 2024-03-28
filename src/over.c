/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 21:43:28 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	over(t_game *cub)
{
	int	i;

	i = -1;
	mlx_delete_image(cub->mlx, cub->map.wall);
	mlx_delete_image(cub->mlx, cub->map.floor);
	mlx_delete_image(cub->mlx, cub->map.player);
	while (++i < cub->map.my)
		free(cub->map.matrix[i]);
	free(cub->map.matrix);
	mlx_terminate(cub->mlx);
}
