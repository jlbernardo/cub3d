/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:29:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 21:46:03 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_matrix(t_game *cub)
{
	int			i;
	const int	fd = open(cub->map.path, O_RDONLY);

	i = -1;
	get_size(cub);
	cub->map.matrix = ft_calloc(cub->map.my, sizeof(char *));
	while (++i < cub->map.my)
		cub->map.matrix[i] = get_next_line(fd);
	get_next_line(fd);
	close(fd);
}

void	get_size(t_game *cub)
{
	int		fd;
	char	*string;

	fd = open(cub->map.path, O_RDONLY);
	string = get_next_line(fd);
	cub->map.mx = 0;
	cub->map.my = 0;
	while (string)
	{
		if ((int)ft_strlen(string) > cub->map.mx)
			cub->map.mx = ft_strlen(string);
		cub->map.my++;
		free(string);
		string = get_next_line(fd);
	}
	free(string);
	close(fd);
}

void	color_block(mlx_image_t *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)img->width)
	{
		y = -1;
		while (++y < (int)img->height)
			mlx_put_pixel(img, x, y, color);
		x++;
	}
}
