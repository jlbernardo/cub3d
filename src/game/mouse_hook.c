/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:11:45 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/19 18:26:02 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_control(double xpos, double ypos, void *param)
{
	t_game			*cub;
	static double	old_x;
	int				sensitivity;

	(void)ypos;
	cub = (t_game *)param;
	sensitivity = 3;
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

void	mouse_click_handler(void *param)
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
