/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 23:21:08 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(t_game *cub, t_coord start)
{
	copy_matrix(cub);
	flood_fill(cub->map_data.copy, cub->map.y, start, '0');
	has_walls(cub, cub->map_data.copy);
}

void	flood_fill(char **map, int rows, t_coord cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= rows || cur.x < 0
		|| cur.x >= ft_strlen(map[(int)cur.y])
		|| map[(int)cur.y][(int)cur.x] == '1'
		|| map[(int)cur.y][(int)cur.x] == '#')
		return ;
	if (map[(int)cur.y][(int)cur.x] == to_fill
		|| is_space(map[(int)cur.y][(int)cur.x])
		|| map[(int)cur.y][(int)cur.x] == '2'
		|| map[(int)cur.y][(int)cur.x] == '3')
		map[(int)cur.y][(int)cur.x] = '#';
	flood_fill(map, rows, (t_coord){cur.x - 1, cur.y}, '0');
	flood_fill(map, rows, (t_coord){cur.x + 1, cur.y}, '0');
	flood_fill(map, rows, (t_coord){cur.x, cur.y - 1}, '0');
	flood_fill(map, rows, (t_coord){cur.x, cur.y + 1}, '0');
}

void	has_walls(t_game *cub, char **map)
{
	int	i;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] == '#' || map[(int)(cub->map.y - 1)][i] == '#')
			cuberror("Map has a broken wall.", cub);
	}
	i = 0;
	while (++i < cub->map.y)
	{
		if (map[i][0] == '#'
		|| map[i][ft_strlen(map[i]) - 1] == '#')
			cuberror("Map has a broken wall.", cub);
	}
}
