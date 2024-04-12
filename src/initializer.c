/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/12 13:50:54 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *cub)
{
	create_matrix(cub);
	load_textures(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d?", false);
	cub->p1 = coordinate(22, 12);
	cub->direction = vector(-1, 0);
	cub->camera_plane = vector(0, 0.66);
	cub->rotation_speed = 0.02;
	cub->move_speed = 0.06;
	draw_ceiling_floor(cub);
	raycast(cub);
	draw_minimap(cub);
}

void	load_textures(t_game *cub)
{
	cub->texture[NO] = mlx_load_png("assets/brick-1l.png");
	cub->texture[SO] = mlx_load_png("assets/brick-2l.png");
	cub->texture[EA] = mlx_load_png("assets/brick-1d.png");
	cub->texture[WE] = mlx_load_png("assets/brick-2d.png");
}

void	create_matrix(t_game *cub)
{
	int			i;
	const int	fd = open(cub->map_path, O_RDONLY);

	i = -1;
	get_size(cub);
	cub->map_matrix = ft_calloc(cub->map.y, sizeof(char *));
	while (++i < cub->map.y)
		cub->map_matrix[i] = get_next_line(fd);
	get_next_line(fd);
	close(fd);
}

void	get_size(t_game *cub)
{
	int		fd;
	char	*string;

	fd = open(cub->map_path, O_RDONLY);
	string = get_next_line(fd);
	cub->map.x = 0;
	cub->map.y = 0;
	while (string)
	{
		if ((int)ft_strlen(string) > cub->map.x)
			cub->map.x = ft_strlen(string);
		cub->map.y++;
		free(string);
		string = get_next_line(fd);
	}
	free(string);
	close(fd);
}
