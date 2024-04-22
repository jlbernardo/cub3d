/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/21 23:06:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	over(t_game *cub, int exit_code)
{
	if (cub->map_matrix)
		free_matrix(cub->map_matrix);
	if (cub->map_data.raw_data)
		free_matrix(cub->map_data.raw_data);
	if (cub->map_data.copy)
		free_matrix(cub->map_data.copy);
	if (cub->map_data.east_tex_path)
		free(cub->map_data.east_tex_path);
	if (cub->map_data.west_tex_path)
		free(cub->map_data.west_tex_path);
	if (cub->map_data.north_tex_path)
		free(cub->map_data.north_tex_path);
	if (cub->map_data.south_tex_path)
		free(cub->map_data.south_tex_path);
	if (cub->mlx)
	{
		delete_images(cub);
		mlx_close_window(cub->mlx);
		mlx_terminate(cub->mlx);
	}
	exit(exit_code);
}

void	delete_images(t_game *cub)
{
	int	i;

	if (cub->screen)
		mlx_delete_image(cub->mlx, cub->screen);
	if (cub->ceiling_floor)
		mlx_delete_image(cub->mlx, cub->ceiling_floor);
	if (cub->minimap)
		mlx_delete_image(cub->mlx, cub->minimap);
	if (cub->miniplayer)
		mlx_delete_image(cub->mlx, cub->miniplayer);
	i = -1;
	while (++i < WEAPON_FRAMES)
	{
		if (cub->weapon[i])
			mlx_delete_image(cub->mlx, cub->weapon[i]);
		if (cub->weapon_t[i])
			mlx_delete_texture(cub->weapon_t[i]);
	}
	i = -1;
	if (*cub->texture)
	{
		while (++i < TOTAL_TEXTURES)
			mlx_delete_texture(cub->texture[i]);
	}
}
