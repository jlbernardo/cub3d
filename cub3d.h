/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/03 01:17:56 by julberna         ###   ########.fr       */
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

# define SIZE		64
# define HEIGHT		512
# define WIDTH		1024
# define PI			3.141592653589793238462643383279502884197169
# define X_AND_Y	2
# define X			0
# define Y			1

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_game
{
	char		**map_matrix;
	char		*map_path;
	mlx_t		*mlx;
	t_coord		map;
	t_coord		p1;
	t_vector	direction;
	t_vector	camera_plane;
	mlx_image_t	*gen;
}				t_game;

typedef struct s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
}				t_draw;

typedef struct s_ray
{
	int			side;
	bool		hit;
	double		camera_x;
	double		perp_wall_dist;
	t_coord		delta_dist;
	t_coord		side_dist;
	t_coord		step;
	t_coord		map;
	t_vector	dir;
}				t_ray;

/* main calls */
void		check(t_game *cub, int argc, char **argv);
void		init(t_game *cub);
void		game(t_game *cub);
void		over(t_game *cub);

/* draw elements */
void		draw(void *cub);
void		draw_player(t_game *cub);
void		draw_matrix(t_game *cub);
void		raycast(t_game *cub, int i);
void		line(t_game *cub, t_coord start, t_coord end, int color);
void		draw_block(t_game *cub, int x, int y, int color);
void		initial_ray_setup(t_ray *ray, t_game *cub, int i);
void		calculate_delta_distance(t_ray *ray);
void		calculate_step_and_initial_side_distance(t_ray *ray, t_game *cub);
void		calculate_wall_distance(t_ray *ray, t_game *cub);
void		draw_line(t_game *cub, t_ray *ray, int i);

/* main game */
void		actions(void *param);
void		after_move_setting(t_game *cub);

/* utils */
void		get_size(t_game *cub);
void		create_matrix(t_game *cub);
t_coord		coordinate(double x, double y);
t_vector	vector(double x, double y);

#endif
