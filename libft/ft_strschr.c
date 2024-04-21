/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:11:45 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 18:15:03 by julberna         ###   ########.fr       */
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
