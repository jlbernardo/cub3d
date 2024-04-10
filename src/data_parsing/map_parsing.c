/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:16 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/10 19:28:20 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

_Bool	get_player_direction(t_game *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map_matrix[++i])
	{
		j = 0;
		while ((cub->map_matrix[i][j] && ft_isdigit(cub->map_matrix[i][j]))
			|| (cub->map_matrix[i][j] && ft_isspace(cub->map_matrix[i][j])))
			j++;
		if (cub->map_matrix[i][j] && ft_isalpha(cub->map_matrix[i][j]))
		{
			if (cub->map_matrix[i][j] == 'N')
				cub->p1_start_direction = NO;
			else if (cub->map_matrix[i][j] == 'E')
				cub->p1_start_direction = EA;
			else if (cub->map_matrix[i][j] == 'S')
				cub->p1_start_direction = SO;
			else if (cub->map_matrix[i][j] == 'W')
				cub->p1_start_direction = WE;
			cub->p1 = coordinate(j, i);
			return (true);
		}
	}
	return (false);
}

void	set_map(t_game *cub, t_get_map_helper *helper)
{
	int	i;

	i = 0;
	cub->map_matrix = (char **)ft_calloc(helper->rows + 1, sizeof(char *));
	while (helper->line_bkp[i] && helper->line_bkp[i][0] != '\n')
	{
		cub->map_matrix[i] = (char *)ft_calloc(ft_strlen(helper->line_bkp[i])
				+ 1, sizeof(char));
		ft_strlcpy(cub->map_matrix[i], helper->line_bkp[i],
			ft_strlen(helper->line_bkp[i]) + 1);
		i++;
	}
	cub->map_matrix[i] = NULL;
}

_Bool	crop_map(t_game *cub, t_get_map_helper *helper, int *i)
{
	while (cub->map_data.raw_data[*i])
	{
		if (!helper->line_bkp || **helper->line_bkp == '\n')
			helper->line_bkp = &cub->map_data.raw_data[*i];
		if (ft_blank_line(cub->map_data.raw_data[*i]))
			helper->broken_map = true;
		else if (cub->map_data.raw_data[*i] && !helper->broken_map)
			helper->rows++;
		else
			return (false);
		*i = *i + 1;
	}
	return (true);
}

_Bool	find_matrix(t_game *cub, t_get_map_helper *helper)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map_data.raw_data[i])
	{
		if (ft_isspace(cub->map_data.raw_data[i][j]))
		{
			helper->line_bkp = &cub->map_data.raw_data[i];
			while (ft_isspace(cub->map_data.raw_data[i][j]))
				j++;
		}
		if (!ft_isdigit(cub->map_data.raw_data[i][j]))
			i++;
		else
		{
			if (!crop_map(cub, helper, &i))
				return (false);
		}
		j = 0;
	}
	return (true);
}

_Bool	get_map(t_game *cub)
{
	t_get_map_helper	helper;

	helper.line_bkp = NULL;
	helper.rows = 0;
	helper.broken_map = false;
	if (!find_matrix(cub, &helper))
	{
		ft_printf("Broken map.\n");
		return (false);
	}
	set_map(cub, &helper);
	return (true);
}
