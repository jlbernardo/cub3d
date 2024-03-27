/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:15:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 20:12:19 by Juliany Ber      ###   ########.fr       */
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

# define WIDTH	1024
# define HEIGHT	512

typedef struct s_mini
{
	int			px;
	int			py;
	int			size;
	int32_t		color;
	mlx_image_t	*player;
}				t_mini;

typedef struct s_game
{
	mlx_t		*mlx;
	t_mini		map;
}				t_game;

/* main calls */
void	init(t_game *cub);
void	game(t_game *cub);
void	finisher(t_game *cub);

/* initializer */
void	mini_map(t_game *cub);
void	draw_player(t_game *cub);

/* main game */
void	actions(void *param);

#endif
