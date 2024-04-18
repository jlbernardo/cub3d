/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:11:45 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/17 21:49:39 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_control(double xpos, double ypos, void* param)
{
	(void)ypos;	
	t_game			*cub;
	static double	old_x;
	int				sensitivity;

	cub = (t_game *)param;
	sensitivity = 2;
	if (old_x < xpos)
	{
		while(sensitivity--)
			rotate_right(cub);
		old_x = xpos;
	}
	else if (old_x > xpos)
	{
		while(sensitivity--)
			rotate_left(cub);
		old_x = xpos;
	}
}

// void	mouse_click_handler(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
void	mouse_click_handler(void* param)
{
	// (void)mods;
	t_game *cub;
	
	cub = (t_game *)param;
	if(mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		// printf("AAAAAAAAAAAAA\n");
		draw_weapon(cub, true);
	}
}
