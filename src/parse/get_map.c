/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:16 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/16 21:28:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_game *cub)
{
	int	map_start;

	cub->map = coordinate(0, 0);
	find_matrix(cub, &map_start);
	set_map(cub, map_start);
}

void	find_matrix(t_game *cub, int *i)
{
	int	j;

	*i = 0;
	while (cub->map_data.raw_data[*i])
	{
		j = 0;
		while (is_space(cub->map_data.raw_data[*i][j]))
			j++;
		if (ft_isdigit(cub->map_data.raw_data[*i][j]))
			break ;
		(*i)++;
	}
	if (!crop_map(cub, *i))
		cuberror("Broken map.", cub);
}

bool	crop_map(t_game *cub, int i)
{
	while (cub->map_data.raw_data[i])
	{
		if (is_blank_line(cub->map_data.raw_data[i]))
			return (false);
		else if (cub->map_data.raw_data[i])
			cub->map.y++;
		i++;
	}
	return (true);
}

void	set_map(t_game *cub, int i)
{
	int	j;
	int	size;

	j = 0;
	cub->map_matrix = (char **)ft_calloc(cub->map.y + 1, sizeof(char *));
	while (j < cub->map.y)
	{
		cub->map_matrix[j] = ft_strtrim(cub->map_data.raw_data[i], "\n");
		size = ft_strlen(cub->map_matrix[j]);
		if (size > cub->map.x)
			cub->map.x = size;
		i++;
		j++;
	}
	cub->map_matrix[j] = NULL;
}

// void	ft_print_matrix(char **matrix)
// {
// 	while (*matrix)
// 	{
// 		ft_printf("%s", *matrix);
// 		matrix++;
// 	}
// }
