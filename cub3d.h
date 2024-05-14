/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/23 22:53:36 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define HORIZON		2
# define MAP_OFFSET		10
# define HEIGHT			600
# define WIDTH			700
# define RATIO			200
# define X				0
# define Y				1
# define WEAPON_FRAMES	15
# define CLOSED_DOOR	4
# define OPEN_DOOR		6

enum e_texture
{
	NO = 0,
	EA,
	SO,
	WE,
	CDL,
	CDD,
	RDL,
	RDD,
	LDD,
	LDL,
	LOGO,
	TOTAL_TEXTURES,
};

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
	bool			open_door;
	bool			closed_door;
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
	int				size;
	char			*north_tex_path;
	char			*east_tex_path;
	char			*south_tex_path;
	char			*west_tex_path;
	char			**raw_data;
	char			**copy;
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
	double			last_fps;
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
	mlx_image_t		*weapon[WEAPON_FRAMES];
	mlx_texture_t	*weapon_t[WEAPON_FRAMES];
	mlx_texture_t	*texture[TOTAL_TEXTURES];
	bool			weapon_reloading;
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
int					get_rgba(int r, int g, int b, int a);
int					count_rows(t_game *cub, char *map_path);
int					set_texture_path(t_game *cub, char *trimmed);
void				check_input(t_game *cub, int argc, char **argv);
bool				rgb_to_hex(t_game *cub, char *rgb, char flag);
void				get_raw_data(char *map_path, t_game *cub);
void				set_direction(t_game *cub, int i, int j);
void				get_player_direction(t_game *cub);
void				find_matrix(t_game *cub, int *i);
void				get_texture_path(t_game *cub);
bool				crop_map(t_game *cub, int i);
void				set_map(t_game *cub, int i);
void				get_colors(t_game *cub);
void				get_map(t_game *cub);

/* map validation */
void				validation(t_game *cub);
void				check_keys(t_game *cub);
void				copy_matrix(t_game *cub);
void				check_extension(t_game *cub);
void				has_walls(t_game *cub, char **map);
void				check_walls(t_game *cub, t_coord start);
void				flood_fill(char **map, int rows, t_coord cur, char to_fill);

/* raycast */
int					get_color(t_texture tex);
void				raycast(t_game *cub);
void				draw_screen(t_game *cub);
void				check_open_door(t_game *cub);
void				draw_line(t_game *cub, int i);
void				wall_side(t_game *cub, int axis);
void				calculate_wall_distance(t_game *cub);
void				calculate_delta_distance(t_game *cub);
void				initial_ray_setup(t_game *cub, int i);
void				pick_a_side(t_game *cub, int side, t_texture *tex);
void				calculate_step_and_initial_side_distance(t_game *cub);
void				texture(t_game *cub, t_coord start, t_coord end, int side);

/* bresenham */
void				algo_setup(t_draw *line, t_coord start, t_coord end);
void				line(t_game *cub, t_coord start, t_coord end,
						int buffer[HEIGHT]);

/* draw other elements */
void				draw_minimap(t_game *cub);
void				load_textures(t_game *cub);
void				draw_background(t_game *cub);
void				load_weapon_images(t_game *cub);
void				load_weapon_textures(t_game *cub);
void				draw_player_on_minimap(t_game *cub);
void				draw_weapon(t_game *cub, bool reload, int i);

/* game mechanics */
void				update(t_game *cub);
void				actions(void *param);
void				open_door(t_game *cub);
void				mouse_click(void *param);
void				rotate_left(t_game *cub);
void				walk_forward(t_game *cub);
void				rotate_right(t_game *cub);
void				walk_backward(t_game *cub);
void				close_open_doors(t_game *cub);
void				walk_sideways(t_game *cub, int key);
void				calculate_frames_per_second(t_game *cub);
void				mouse_control(double xpos, double ypos, void *param);

/* utils */
int					count_tabs(char *str);
char				*transform_tabs(char *str);
void				cuberror(char *message, t_game *cub);
void				delete_images(t_game *cub);
void				free_matrix(char **split);
bool				is_space(char c);
bool				is_blank_line(char *line);
bool				is_alpha_numeric_line(char *line);
t_coord				coordinate(double x, double y);
t_vector			vector(double x, double y);

#endif
