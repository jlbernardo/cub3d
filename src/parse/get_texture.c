/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:06:07 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:38 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_path(t_game *cub)
{
	char	**temp;
	char	*trimmed;
	int		keys;

	temp = cub->map_data.raw_data;
	keys = 0;
	while (*temp)
	{
		trimmed = ft_strtrim(*temp, "\n ");
		keys += set_texture_path(cub, trimmed);
		if (keys == 15)
		{
			free(trimmed);
			return ;
		}
		temp++;
		free(trimmed);
	}
	cuberror("Texture path not found.", cub);
}

int	set_texture_path(t_game *cub, char *trimmed)
{
	int	keys;

	keys = 0;
	if (!ft_strncmp("NO", trimmed, 2) && (keys & (1 << 3)) < 1)
	{
		cub->map_data.north_tex_path = ft_strdup(ft_strchr(trimmed, '.'));
		keys |= (1 << 3);
	}
	else if (!ft_strncmp("EA", trimmed, 2) && (keys & (1 << 2)) < 1)
	{
		cub->map_data.east_tex_path = ft_strdup(ft_strchr(trimmed, '.'));
		keys |= (1 << 2);
	}
	else if (!ft_strncmp("SO", trimmed, 2) && (keys & (1 << 1)) < 1)
	{
		cub->map_data.south_tex_path = ft_strdup(ft_strchr(trimmed, '.'));
		keys |= (1 << 1);
	}
	else if (!ft_strncmp("WE", trimmed, 2) && (keys & (1 << 0)) < 1)
	{
		cub->map_data.west_tex_path = ft_strdup(ft_strchr(trimmed, '.'));
		keys |= 1;
	}
	return (keys);
}
