/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/12 21:52:18 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}

bool	check_extension(char *filename)
{
	int	lenght;

	lenght = ft_strlen(filename);
	if (lenght < 4)
	{
		ft_printf("Error\nWrong file extension\n");
		return (false);
	}
	if (!ft_strcmp((filename + (lenght - 4)), ".cub"))
		return (true);
	ft_printf("Error\nWrong file extension\n");
	return (false);
}

bool	check_keys(t_game *cub)
{
	int		i;
	char	*trimmed;

	i = -1;
	while (cub->map_matrix[++i])
	{
		trimmed = ft_strtrim(cub->map_matrix[i], "10NESW \t\n\v\r\f");
		if(*trimmed == '\0')
			free (trimmed);
		else
		{
			free (trimmed);
			ft_printf("Wrong character found!\n");
			return (false);
		}
	}
	return (true);
}

void	fill(char **map, t_coord size, t_coord cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[(int)cur.y][(int)cur.x] == '1' || map[(int)cur.y][(int)cur.x] == '#')
		return ;
	if (map[(int)cur.y][(int)cur.x] == to_fill)
	{
		map[(int)cur.y][(int)cur.x] = '#';
		return ;
	}
	map[(int)cur.y][(int)cur.x] = '#';
	fill(map, size, (t_coord){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_coord){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_coord){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_coord){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(t_game *cub, t_coord size, t_coord start)
{
	// fill(cub->map_matrix, size, start, cub->map_matrix[(int)start.y][(int)start.x]);
	fill(cub->map_matrix, size, start, '0');
}

bool validation_suite(t_game * cub)
{
	if (!check_extension(cub->map_path) || !check_keys(cub))
		return (false);
	flood_fill(cub, cub->map, cub->p1);
	ft_print_matrix(cub->map_matrix);
	return (true);
}
