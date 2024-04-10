/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/10 20:05:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

# define HORIZON 2
# define HEIGHT 980
# define WIDTH 1020
# define X 0
# define Y 1
# define NO 0
# define SO 1
# define EA 2
# define WE 3

typedef struct s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_ray
{
	int				line_height;
	int				side;
	bool			hit;
	double			camera_x;
	double			perp_wall_dist;
	t_coord			delta_dist;
	t_coord			side_dist;
	t_coord			step;
	t_coord			map;
	t_vector		dir;
}					t_ray;

typedef struct s_map_data
{
	char			*north_tex_path;
	char			*east_tex_path;
	char			*south_tex_path;
	char			*west_tex_path;
	char			**raw_data;
	uint32_t		c_color;
	uint32_t		f_color;
}					t_map_data;

typedef struct s_game
{
	int				p1_start_direction;
	char			**map_matrix;
	char			*map_path;
	mlx_t			*mlx;
	t_ray			ray;
	double			time;
	double			old_time;
	double			move_speed;
	double			rotation_speed;
	t_vector		camera_plane;
	t_vector		direction;
	t_coord			map;
	t_coord			p1;
	t_map_data		map_data;
	mlx_image_t		*screen;
	mlx_image_t		*ceiling_floor;
	mlx_texture_t	*texture[4];
}					t_game;

typedef struct s_draw
{
	int				error;
	int				step_x;
	int				step_y;
	int				delta_x;
	int				delta_y;
}					t_draw;

typedef struct s_get_map_helper
{
	char			**line_bkp;
	int				rows;
	_Bool			broken_map;
}					t_get_map_helper;

typedef struct s_texture
{
	int				buffer[HEIGHT];
	int				color;
	double			x;
	double			y;
	double			step;
	double			position;
	double			surface_x;
	mlx_texture_t	*img;
}					t_texture;

/* main calls */
void				check(t_game *cub, int argc, char **argv);
_Bool				init(t_game *cub);
void				game(t_game *cub);
int					over(t_game *cub);

/* raycast */
void				raycast(t_game *cub);
void				draw_line(t_game *cub, int i);
void				draw_ceiling_floor(t_game *cub);
void				wall_side(t_game *cub, int axis);
void				calculate_wall_distance(t_game *cub);
void				initial_ray_setup(t_game *cub, int i);
void				calculate_delta_distance(t_game *cub);
void				calculate_frames_per_second(t_game *cub);
void				pick_a_side(t_game *cub, int side, t_texture *tex);
void				calculate_step_and_initial_side_distance(t_game *cub);
void				put_texture(t_game *cub, t_coord start, t_coord end,
						int side);

/* bresenham */
void				line(t_game *cub, t_coord start, t_coord end,
						int buffer[HEIGHT]);
void				algo_setup(t_draw *line, t_coord start, t_coord end);

/* game mechanics */
void				actions(void *param);
void				walk_back(t_game *cub);
void				rotate_left(t_game *cub);
void				walk_forward(t_game *cub);
void				rotate_right(t_game *cub);
void				walk_sideways(t_game *cub, int key);

/* utils */
int					get_color(t_texture tex);
void				get_size(t_game *cub);
void				load_textures(t_game *cub);
void				create_matrix(t_game *cub);
t_coord				coordinate(double x, double y);
t_vector			vector(double x, double y);
void				free_matrix(char **split);
int					free_data(t_game *cub);
void				ft_print_matrix(char **matrix);

/* map parsing */
int					ft_isspace(char c);
int					ft_blank_line(char *line);
int					count_rows(int fd);
char				**get_raw_data(char *map_path);
_Bool				parsing_suite(t_game *cub);
int					get_texture_path(t_game *cub);
_Bool				get_colors(t_game *cub);
_Bool				get_map(t_game *cub);
_Bool				get_player_direction(t_game *cub);

#endif
