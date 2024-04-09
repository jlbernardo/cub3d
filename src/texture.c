/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:57:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/09 19:50:14 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_texture(t_game *cub, t_coord start, t_coord end, int line_height)
{
	int			i;
	double		surface_x;
	t_texture	image;

	surface_x = cub->p1.x + cub->ray.perp_wall_dist * cub->ray.dir.x;
	surface_x -= floor(surface_x);
	image.x = cub->wall->width - (surface_x * (double)cub->wall->width);
	image.step = (double)cub->wall->height / line_height;
	image.position
		= (start.x - HEIGHT / HORIZON + line_height / HORIZON) * image.step;
	i = start.x;
	while (i < end.x)
	{
		image.y = (int)image.position & (cub->wall->height - 1);
		image.position += image.step;
		image.color = get_color(cub->wall, image.x, image.y);
		image.buffer[i] = image.color;
		i++;
	}
	line(cub, start, end, 0x00000000, image.buffer);
}

int	get_color(mlx_texture_t *texture, int texture_x, int texture_y)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	*p;

	p = (int *)texture->pixels + texture_x + texture_y * texture->width;
	r = ((*p) & 0xFF) >> 0;
	g = ((*p) & 0xFF00) >> 8;
	b = ((*p) & 0xFF0000) >> 16;
	a = ((*p) & 0xFF000000) >> 24;
	return (r << 24 | g << 16 | b << 8 | a);
}
/* code below is more performatic */
// int32_t	pixel;

// pixel = *((int32_t *)texture->pixels
// 	+ (size_t)(texture_y * texture->width + texture_x));
// pixel = ((pixel & 0xFF) << 24) | ((pixel & 0xFF00) << 8)
// 	| ((pixel & 0xFF0000) >> 8) | ((pixel & 0xFF000000) >> 24);
// return (pixel);
