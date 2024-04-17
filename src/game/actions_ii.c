/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:11:45 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/17 16:27:03 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_control(void *param)
{
	int32_t			x;
	int32_t			y;
	t_game			*cub;
	static int32_t	old_x;

	cub = (t_game *)param;
	mlx_get_mouse_pos(cub->mlx, &x, &y);
	if (old_x < x || x > WIDTH)
	{
		rotate_right(cub);
		old_x = x;
	}
	else if (old_x > x || x < 0)
	{
		rotate_left(cub);
		old_x = x;
	}
}

void	open_door(t_game *cub)
{
	int	i;
	int	j;
	int	px;
	int	py;

	i = 0;
	px = (int)cub->p1.x;
	py = (int)cub->p1.y;
	while (i < cub->map.y)
	{
		j = 0;
		while (j < (int)ft_strlen(cub->map_matrix[i]))
		{
			if (cub->map_matrix[i][j] == '2')
			{
				if ((px == j || px == j + 1 || px == j - 1)
					&& (py == i || py == i + 1 || py == i - 1))
					cub->map_matrix[i][j] = '3';
			}
			j++;
		}
		i++;
	}
}
