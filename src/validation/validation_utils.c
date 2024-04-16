/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/15 22:11:49 by aperis-p         ###   ########.fr       */
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
		|| is_space(map[(int)cur.y][(int)cur.x]))
		map[(int)cur.y][(int)cur.x] = '#';
	flood_fill(map, rows, (t_coord){cur.x - 1, cur.y}, '0');
	flood_fill(map, rows, (t_coord){cur.x + 1, cur.y}, '0');
	flood_fill(map, rows, (t_coord){cur.x, cur.y - 1}, '0');
	flood_fill(map, rows, (t_coord){cur.x, cur.y + 1}, '0');
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
