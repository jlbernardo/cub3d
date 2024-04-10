/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:57:39 by julberna          #+#    #+#             */
/*   Updated: 2024/04/09 21:25:59 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_texture(t_game *cub, t_coord start, t_coord end, int side)
{
	int				i;
	double			surface_x;
	t_texture		tex;
	mlx_texture_t	*img;

	choose_side(cub, side, img);
	surface_x = cub->p1.x + cub->ray.perp_wall_dist * cub->ray.dir.x;
	surface_x -= floor(surface_x);
	tex.x = img->width - (surface_x * (double)img->width);
	tex.step = (double)img->height / cub->ray.line_height;
	tex.position = (start.x - HEIGHT / HORIZON + cub->ray.line_height / HORIZON)
		* tex.step;
	i = start.x;
	while (i < end.x)
	{
		tex.y = (int)tex.position & (img->height - 1);
		tex.position += tex.step;
		tex.color = get_color(img, tex.x, tex.y);
		tex.buffer[i] = tex.color;
		i++;
	}
	line(cub, start, end, tex.buffer);
}

void	choose_side(t_game *cub, int side, mlx_texture_t *img)
{
	if (side == NO)
		img = cub->wall;
	if (side == SO)
		img = cub->wall;
	if (side == EA)
		img = cub->wall;
	if (side == WE)
		img = cub->wall;
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
