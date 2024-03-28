/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 21:45:15 by Juliany Ber      ###   ########.fr       */
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

typedef struct s_mini
{
	int			px;
	int			py;
	int			mx;
	int			my;
	int			size;
	char		*path;
	char		**matrix;
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
}				t_mini;

typedef struct s_game
{
	mlx_t		*mlx;
	t_mini		map;
}				t_game;

/* main calls */
void	check(t_game *cub, int argc, char **argv);
void	init(t_game *cub);
void	game(t_game *cub);
void	over(t_game *cub);

/* initializer */
void	mini_map(t_game *cub);
void	draw_player(t_game *cub);
void	draw_matrix(t_game *cub);

/* main game */
void	actions(void *param);

/* utils */
void	get_size(t_game *cub);
void	create_matrix(t_game *cub);
void	color_block(mlx_image_t *img, int color);

#endif
