/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/18 18:10:21 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validation(t_game *cub)
{
	check_extension(cub);
	check_keys(cub);
	check_walls(cub, cub->p1);
}

void	check_extension(t_game *cub)
{
	int	lenght;

	lenght = ft_strlen(cub->map_path);
	if (lenght < 4 || ft_strcmp((cub->map_path + (lenght - 4)), ".cub"))
		cuberror("Wrong file extension.", cub);
}

void	check_keys(t_game *cub)
{
	int		i;
	bool	player_found;

	i = -1;
	player_found = false;
	while (cub->map_matrix[++i])
	{
		if (ft_strchr(cub->map_matrix[i], 'N')
			|| ft_strchr(cub->map_matrix[i], 'E')
			|| ft_strchr(cub->map_matrix[i], 'S')
			|| ft_strchr(cub->map_matrix[i], 'W'))
		{
			if (player_found)
				cuberror("More than one player found.", cub);
			player_found = true;
		}
	}
}

void	check_walls(t_game *cub, t_coord start)
{
	copy_matrix(cub);
	flood_fill(cub->map_data.copy, cub->map.y, start, '0');
	has_walls(cub, cub->map_data.copy);
}

void	has_walls(t_game *cub, char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '#')
			cuberror("Map has a broken wall.", cub);
		i++;
	}
	i = 0;
	while (map[(int)(cub->map.y - 1)][i])
	{
		if (map[(int)(cub->map.y - 1)][i] == '#')
			cuberror("Map has a broken wall.", cub);
		i++;
	}
	i = 1;
	while (i < cub->map.y)
	{
		if (map[i][0] != '#'
		&& map[i][ft_strlen(map[i]) - 1] != '#')
			i++;
		else
			cuberror("Map has a broken wall.", cub);
	}
}
