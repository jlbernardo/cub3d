/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/08 21:26:32 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_data(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map.y)
		free(cub->map_matrix[i]);
	free(cub->map_matrix);
	free(cub->map_data.north_tex_path);
	free(cub->map_data.east_tex_path);
	free(cub->map_data.south_tex_path);
	free(cub->map_data.west_tex_path);
	exit (EXIT_SUCCESS);
}

int	over(t_game *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map.y)
		free(cub->map_matrix[i]);
	free(cub->map_matrix);
	free(cub->map_data.north_tex_path);
	free(cub->map_data.east_tex_path);
	free(cub->map_data.south_tex_path);
	free(cub->map_data.west_tex_path);
	mlx_delete_image(cub->mlx, cub->screen);
	mlx_delete_image(cub->mlx, cub->ceiling_floor);
	mlx_terminate(cub->mlx);
	return (EXIT_SUCCESS);
}
