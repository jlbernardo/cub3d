/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/14 23:09:44 by julberna         ###   ########.fr       */
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

# define HORIZON	2
# define MAP_OFFSET	10
# define HEIGHT		600
# define WIDTH		800
# define RATIO		200
# define X			0
# define Y			1
# define NO			0
# define SO			1
# define EA			2
# define WE			3

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
	t_coord			mini_size;
	t_coord			map;
	t_coord			p1;
	t_map_data		map_data;
	mlx_image_t		*screen;
	mlx_image_t		*minimap;
	mlx_image_t		*miniplayer;
	mlx_image_t		*ceiling_floor;
	mlx_texture_t	*texture[4];
	mlx_texture_t	*door;
	mlx_texture_t	*logo;
}					t_game;

typedef struct s_draw
{
	int				i;
	int				error;
	int				step_x;
	int				step_y;
	int				delta_x;
	int				delta_y;
}					t_draw;

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
void				parse(t_game *cub, int argc, char **argv);
void				init(t_game *cub);
void				game(t_game *cub);
void				over(t_game *cub, int exit_code);

/* map parsing */
int					set_texture_path(t_game *cub, char *trimmed);
int					count_rows(t_game *cub, char *map_path);
int					get_rgba(int r, int g, int b, int a);
void				get_map(t_game *cub);
void				get_colors(t_game *cub);
void				get_texture_path(t_game *cub);
void				get_player_direction(t_game *cub);
void				set_direction(t_game *cub, int i, int j);
void				get_raw_data(char *map_path, t_game *cub);
bool				rgb_to_hex(t_game *cub, char *rgb, char flag);
void				set_map(t_game *cub, int i);
void				check_input(t_game *cub, int argc, char **argv);
void				find_matrix(t_game *cub, int *i);
bool				crop_map(t_game *cub, int i);

/* raycast */
void				raycast(t_game *cub);
void				draw_minimap(t_game *cub);
void				draw_line(t_game *cub, int i);
void				draw_ceiling_floor(t_game *cub);
void				wall_side(t_game *cub, int axis);
void				draw_player_on_minimap(t_game *cub);
void				calculate_wall_distance(t_game *cub);
void				initial_ray_setup(t_game *cub, int i);
void				calculate_delta_distance(t_game *cub);
void				calculate_frames_per_second(t_game *cub);
void				pick_a_side(t_game *cub, int side, t_texture *tex);
void				calculate_step_and_initial_side_distance(t_game *cub);
void				put_texture(t_game *cub, t_coord start, t_coord end,
						int side);

/* bresenham */
void				algo_setup(t_draw *line, t_coord start, t_coord end);
void				line(t_game *cub, t_coord start, t_coord end,
						int buffer[HEIGHT]);

/* game mechanics */
void				actions(void *param);
void				walk_back(t_game *cub);
void				rotate_left(t_game *cub);
void				walk_forward(t_game *cub);
void				rotate_right(t_game *cub);
void				walk_sideways(t_game *cub, int key);

/* utils */
int					get_color(t_texture tex);
bool				is_space(char c);
bool				is_blank_line(char *line);
void				free_matrix(char **split);
void				load_textures(t_game *cub);
void				delete_images(t_game *cub);
void				cuberror(char *message, t_game *cub);
t_coord				coordinate(double x, double y);
t_vector			vector(double x, double y);
// void				ft_print_matrix(char **matrix);

#endif
