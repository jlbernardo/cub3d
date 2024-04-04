/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/04 20:44:42 by aperis-p         ###   ########.fr       */
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

# define HEIGHT		1080
# define WIDTH		1220
# define X			0
# define Y			1
# define NO			0
# define SO			1
# define EA			2
# define WE			3

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

typedef struct s_game
{
	char		**map_matrix;
	char		*map_path;
	mlx_t		*mlx;
	t_ray		ray;
	double		time;
	double		old_time;
	double		move_speed;
	double		rotation_speed;
	t_vector	camera_plane;
	t_vector	direction;
	t_coord		map;
	t_coord		p1;
	mlx_image_t	*screen;
	mlx_image_t	*ceiling_floor;
}				t_game;

typedef struct s_draw
{
	int			error;
	int			step_x;
	int			step_y;
	int			delta_x;
	int			delta_y;
}				t_draw;

/* main calls */
void		check(t_game *cub, int argc, char **argv);
void		init(t_game *cub);
void		game(t_game *cub);
void		over(t_game *cub);

/* raycast */
void		raycast(t_game *cub);
void		draw_line(t_game *cub, int i);
void		wall_side(t_game *cub, int axis);
void		calculate_wall_distance(t_game *cub);
void		initial_ray_setup(t_game *cub, int i);
void		calculate_delta_distance(t_game *cub);
void		calculate_frames_per_second(t_game *cub);
void		calculate_step_and_initial_side_distance(t_game *cub);
void		draw_ceiling_floor(t_game *cub);

/* bresenham */
void		algo_setup(t_draw *line, t_coord start, t_coord end);
void		line(t_game *cub, t_coord start, t_coord end, int color);

/* main game */
void		actions(void *param);
void		walk_back(t_game *cub);
void		walk_forward(t_game *cub);
void		rotate_left(t_game *cub);
void		rotate_right(t_game *cub);

/* utils */
void		get_size(t_game *cub);
void		create_matrix(t_game *cub);
t_coord		coordinate(double x, double y);
t_vector	vector(double x, double y);

#endif
