/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/12 16:29:45 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_game *cub)
{
	if (cub->map_matrix)
		free_matrix(cub->map_matrix);
	free_matrix(cub->map_data.raw_data);
	free(cub->map_data.north_tex_path);
	free(cub->map_data.east_tex_path);
	free(cub->map_data.south_tex_path);
	free(cub->map_data.west_tex_path);
	exit(EXIT_SUCCESS);
}

void	over(t_game *cub, char *flag)
{
	if (ft_strchr(flag, 'M'))
	{
		if (cub->map_matrix)
			free_matrix(cub->map_matrix);
		free_matrix(cub->map_data.raw_data);
		free(cub->map_data.north_tex_path);
		free(cub->map_data.east_tex_path);
		free(cub->map_data.south_tex_path);
		free(cub->map_data.west_tex_path);
	}
	if (ft_strchr(flag, 'I'))
	{
		mlx_delete_image(cub->mlx, cub->screen);
		mlx_delete_image(cub->mlx, cub->ceiling_floor);
		mlx_terminate(cub->mlx);
	}
	exit(EXIT_SUCCESS);
}
