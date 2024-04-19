/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/18 20:55:34 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_rows_from_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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

void	copy_matrix(t_game *cub)
{
	int		i;

	i = -1;
	cub->map_data.copy = ft_calloc(cub->map.y + 1, sizeof(char *));
	while (++i < cub->map.y)
		cub->map_data.copy[i] = ft_strdup(cub->map_matrix[i]);
	cub->map_data.copy[i] = NULL;
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

// void	ft_print_matrix(char **matrix)
// {
// 	while (*matrix)
// 	{
// 		ft_printf("%s", *matrix);
// 		matrix++;
// 	}
// 	ft_printf("\n");
// 	ft_printf("\n");
// }
