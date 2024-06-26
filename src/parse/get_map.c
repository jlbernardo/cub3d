/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:16 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/23 15:59:20 by julberna         ###   ########.fr       */
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
		if (count_tabs(cub->map_matrix[j]) > 0)
			cub->map_matrix[j] = transform_tabs(cub->map_matrix[j]);
		size = ft_strlen(cub->map_matrix[j]);
		if (size > cub->map.x)
			cub->map.x = size;
		i++;
		j++;
	}
	cub->map_matrix[j] = NULL;
}

char	*transform_tabs(char *str)
{
	char		*transformed;
	int			i;
	int			j;

	transformed = (char *)ft_calloc((count_tabs(str) * 4)
			+ ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			transformed[j] = ' ';
			transformed[j + 1] = ' ';
			transformed[j + 2] = ' ';
			transformed[j + 3] = ' ';
			j += 4;
			i++;
		}
		else
			transformed[j++] = str[i++];
	}
	free(str);
	return (transformed);
}
