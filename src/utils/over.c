/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:53:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/13 17:52:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	over(t_game *cub, int exit_code)
{
	if (cub->map_matrix)
		free_matrix(cub->map_matrix);
	if (cub->map_data.raw_data)
		free_matrix(cub->map_data.raw_data);
	if (cub->map_data.east_tex_path)
		free(cub->map_data.east_tex_path);
	if (cub->map_data.west_tex_path)
		free(cub->map_data.west_tex_path);
	if (cub->map_data.north_tex_path)
		free(cub->map_data.north_tex_path);
	if (cub->map_data.south_tex_path)
		free(cub->map_data.south_tex_path);
	if (cub->mlx)
		delete_images(cub);
	exit(exit_code);
}

void	delete_images(t_game *cub)
{
	int	i;

	i = -1;
	if (cub->screen)
		mlx_delete_image(cub->mlx, cub->screen);
	if (cub->ceiling_floor)
		mlx_delete_image(cub->mlx, cub->ceiling_floor);
	if (cub->minimap)
		mlx_delete_image(cub->mlx, cub->minimap);
	if (cub->miniplayer)
		mlx_delete_image(cub->mlx, cub->miniplayer);
	if (cub->logo)
		mlx_delete_texture(cub->logo);
	if (*cub->texture)
	{
		while (++i < 4)
			mlx_delete_texture(cub->texture[i]);
	}
	mlx_terminate(cub->mlx);
}

void	cuberror(char *message, t_game *cub)
{
	write(STDERR_FILENO, "\033[1;31mError!\033[0m\n", 18);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	over(cub, EXIT_FAILURE);
}
