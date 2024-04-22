/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:29:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 23:50:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_colors(t_game *cub)
{
	char	**temp;
	char	*trimmed;
	int		keys;

	temp = cub->map_data.raw_data;
	keys = 0;
	while (*temp)
	{
		trimmed = ft_strtrim(*temp, " ");
		if (!ft_strncmp("C", trimmed, 1) && (keys & (1 << 1)) < 1)
		{
			if (rgb_to_hex(cub, trimmed, 'C'))
				keys |= (1 << 1);
		}
		if (!ft_strncmp("F", trimmed, 1) && (keys & (1 << 0)) < 1)
		{
			if (rgb_to_hex(cub, trimmed, 'F'))
				keys |= 1;
		}
		temp++;
		free(trimmed);
	}
	if (keys == 3)
		return ;
	cuberror("Ceiling/floor color information missing.", cub);
}

bool	rgb_to_hex(t_game *cub, char *rgb, char flag)
{
	char	*trimmed;
	char	**colors;
	int		rgba[3];
	int		i;

	trimmed = ft_strtrim(rgb, "CF ");
	colors = ft_split(trimmed, ',');
	free(trimmed);
	i = -1;
	while (++i < 3)
		rgba[i] = ft_atoi(colors[i]);
	free_matrix(colors);
	if ((rgba[0] >= 0 && rgba[0] <= 255) && (rgba[1] >= 0 && rgba[1] <= 255)
		&& (rgba[2] >= 0 && rgba[2] <= 255))
	{
		if (flag == 'C')
			cub->map_data.c_color = get_rgba(rgba[0], rgba[1], rgba[2], 0xFF);
		else if (flag == 'F')
			cub->map_data.f_color = get_rgba(rgba[0], rgba[1], rgba[2], 0xFF);
		return (true);
	}
	free(rgb);
	cuberror("Color out of range.", cub);
	return (false);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
