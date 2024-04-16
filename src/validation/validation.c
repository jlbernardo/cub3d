/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/16 14:43:28 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	has_walls(t_game *cub, int row)
{
	int	i;

	i = 0;
	while (cub->map_matrix[0][i])
	{
		if (cub->map_matrix[0][i] == '#')
			cuberror("Map has a broken wall.", cub);
		i++;
	}
	i = 0;
	while (cub->map_matrix[row - 1][i])
	{
		if (cub->map_matrix[row - 1][i] == '#')
			cuberror("Map has a broken wall.", cub);
		i++;
	}
	i = 1;
	while (i < row)
	{
		if (cub->map_matrix[i][0] != '#'
		&& cub->map_matrix[i][ft_strlen(cub->map_matrix[i]) - 1] != '#')
			i++;
		else
			cuberror("Map has a broken wall.", cub);
	}
}

void	check_walls(t_game *cub, t_coord start)
{
	flood_fill(cub->map_matrix,
		count_rows_from_map(cub->map_matrix), start, '0');
	has_walls(cub, count_rows_from_map(cub->map_matrix));
}

void	validation(t_game *cub)
{
	check_extension(cub);
	check_keys(cub);
	check_walls(cub, cub->p1);
}
