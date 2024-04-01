/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/01 01:23:42 by julberna         ###   ########.fr       */
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

typedef struct s_player
{
	int		x;
	int		y;
	float	angle;
	float	delta_x;
	float	delta_y;
}				t_player;

typedef struct s_matrix
{
	int			x;
	int			y;
	char		*path;
	char		**matrix;
}				t_matrix;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	p1;
	t_matrix	map;
	mlx_image_t	*gen;
}				t_game;

/* main calls */
void	check(t_game *cub, int argc, char **argv);
void	init(t_game *cub);
void	game(t_game *cub);
void	over(t_game *cub);

/* draw elements */
void	draw(void *cub);
void	raycast(t_game *cub);
void	draw_player(t_game *cub);
void	draw_matrix(t_game *cub);
void	draw_block(t_game *cub, int x, int y, int color);
void	steep(t_game *cub, int delta_x, int delta_y);
void	shallow(t_game *cub, int delta_x, int delta_y);

/* main game */
void	actions(void *param);

/* utils */
void	get_size(t_game *cub);
void	create_matrix(t_game *cub);

#endif
