/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/02 16:32:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>

# define SIZE	64
# define WIDTH	1024
# define HEIGHT	512
# define PI		3.141592653589793238462643383279502884197169
# define X_AND_Y	2
# define X			0
# define Y			1

typedef struct s_cast
{
	float			ray_x;
	float			ray_y;
	float			map_x;
	float			map_y;
	int			count;
	int			map_pos;
	int			depth_of_field;
	float		x_offset;
	float		y_offset;
	float		angle;
}				t_cast;

typedef struct s_player
{
	float		x;
	float		y;
	float	angle;
	float	delta_x;
	float	delta_y;
}				t_player;

typedef struct s_matrix
{
	float			x;
	float			y;
	char		*path;
	char		**matrix;
}				t_matrix;

typedef struct s_game
{
	mlx_t		*mlx;
	t_cast		ray;
	t_player	p1;
	t_matrix	map;
	mlx_image_t	*gen;
}				t_game;

/*  calls */
void	check(t_game *cub, int argc, char **argv);
void	init(t_game *cub);
void	game(t_game *cub);
void	over(t_game *cub);

/* draw elements */
void	draw(void *cub);
void	raycast(t_game *cub);
void	draw_player(t_game *cub);
void	draw_matrix(t_game *cub);
void	line(t_game *cub, int x1, int y1, int x2, int y2);
void	draw_block(t_game *cub, int x, int y, int color);
void	steep(t_game *cub, int delta_x, int delta_y);
void	shallow(t_game *cub, int delta_x, int delta_y);

typedef struct s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
}				t_draw;

/*  game */
void	actions(void *param);

/* utils */
void	get_size(t_game *cub);
void	create_matrix(t_game *cub);

#endif
