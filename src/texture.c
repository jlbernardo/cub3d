/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:57:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/09 22:39:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_texture(t_game *cub, t_coord start, t_coord end, int side)
{
	int				i;
	t_texture		tex;

	pick_a_side(cub, side, &tex);
	tex.surface_x -= floor(tex.surface_x);
	tex.x = tex.img->width - (tex.surface_x * (double)tex.img->width);
	tex.step = (double)tex.img->height / cub->ray.line_height;
	tex.position = (start.x - HEIGHT / HORIZON + cub->ray.line_height / HORIZON)
		* tex.step;
	i = start.x;
	while (i < end.x)
	{
		tex.y = (int)tex.position & (tex.img->height - 1);
		tex.position += tex.step;
		tex.color = get_color(tex.img, tex.x, tex.y);
		tex.buffer[i] = tex.color;
		i++;
	}
	line(cub, start, end, tex.buffer);
}

void	pick_a_side(t_game *cub, int side, t_texture *tex)
{
	if (side == NO || side == SO)
	{
		tex->surface_x = cub->p1.x + cub->ray.perp_wall_dist * cub->ray.dir.x;
		tex->img = cub->wall;
	}
	if (side == EA || side == WE)
	{
		tex->surface_x = cub->p1.y + cub->ray.perp_wall_dist * cub->ray.dir.y;
		tex->img = cub->wall;
	}
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
