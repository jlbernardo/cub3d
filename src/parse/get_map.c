/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:16 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/15 22:12:28 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_game *cub)
{
	t_get_map_helper	helper;

	helper.line_bkp = NULL;
	helper.rows = 0;
	helper.broken_map = false;
	find_matrix(cub, &helper);
	set_map(cub, &helper);
}

void	find_matrix(t_game *cub, t_get_map_helper *helper)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map_data.raw_data[i])
	{
		if (is_space(cub->map_data.raw_data[i][j]))
		{
			helper->line_bkp = &cub->map_data.raw_data[i];
			while (is_space(cub->map_data.raw_data[i][j]))
				j++;
		}
		if (!ft_isdigit(cub->map_data.raw_data[i][j]))
			i++;
		else if (!crop_map(cub, helper, &i))
			cuberror("Broken or misplaced map.", cub);
		j = 0;
	}
}

bool	crop_map(t_game *cub, t_get_map_helper *helper, int *i)
{
	while (cub->map_data.raw_data[*i])
	{
		if (!helper->line_bkp || **helper->line_bkp == '\n')
			helper->line_bkp = &cub->map_data.raw_data[*i];
		if (is_blank_line(cub->map_data.raw_data[*i]))
			helper->broken_map = true;
		else if (cub->map_data.raw_data[*i] && !helper->broken_map
			&& is_alpha_numeric_line(cub->map_data.raw_data[*i]))
			helper->rows++;
		else
			return (false);
		*i = *i + 1;
	}
	return (true);
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
