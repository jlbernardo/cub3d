/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:11:45 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 22:14:38 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_game *cub)
{
	int			i;
	int			j;
	const int	px = (int)cub->p1.x;
	const int	py = (int)cub->p1.y;

	i = -1;
	while (++i < cub->map.y)
	{
		j = -1;
		while (++j < (int)ft_strlen(cub->map_matrix[i]))
		{
			if (cub->map_matrix[i][j] == '2')
			{
				if ((px == j || px == j + 1 || px == j - 1)
					&& (py == i || py == i + 1 || py == i - 1))
					cub->map_matrix[i][j] = '3';
			}
		}
	}
}

void	close_open_doors(t_game *cub)
{
	int	i;
	int	j;
	int	px;
	int	py;

	i = -1;
	px = (int)cub->p1.x;
	py = (int)cub->p1.y;
	while (++i < cub->map.y)
	{
		j = -1;
		while (++j < (int)ft_strlen(cub->map_matrix[i]))
		{
			if (cub->map_matrix[i][j] == '3')
			{
				if ((px != j && px != j + 1 && px != j - 1)
					|| (py != i && py != i + 1 && py != i - 1))
					cub->map_matrix[i][j] = '2';
			}
		}
	}
}

void	mouse_control(double xpos, double ypos, void *param)
{
	t_game			*cub;
	static double	old_x;
	int				sensitivity;

	(void)ypos;
	cub = (t_game *)param;
	sensitivity = 2;
	if (old_x < xpos)
	{
		while (sensitivity--)
			rotate_right(cub);
		old_x = xpos;
	}
	else if (old_x > xpos)
	{
		while (sensitivity--)
			rotate_left(cub);
		old_x = xpos;
	}
}

void	mouse_click(void *param)
{
	t_game	*cub;
	double	temp;

	cub = (t_game *)param;
	temp = mlx_get_time();
	if (mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_LEFT)
		|| cub->weapon_reloading == true)
	{
		if (temp - cub->last_fps > 0.05)
		{
			draw_weapon(cub, true, 1);
			cub->last_fps = temp;
		}
	}
}
