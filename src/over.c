/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/03 22:26:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	over(t_game *cub)
{
	int	i;

	i = -1;
	mlx_delete_image(cub->mlx, cub->screen);
	while (++i < cub->map.y)
		free(cub->map_matrix[i]);
	free(cub->map_matrix);
	mlx_terminate(cub->mlx);
}
