/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditionals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:35:52 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 16:49:51 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing_suite(t_game *cub)
{
	cub->map_data.raw_data = get_raw_data(cub->map_path);
	if (!get_texture_path(cub) || !get_colors(cub) || !get_map(cub)
		|| !get_player_direction(cub))
		return (false);
	return (true);
}

bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n'
		|| c == '\f')
		return (true);
	return (false);
}

bool	is_blank_line(char *line)
{
	while (*line && is_space(*line))
		line++;
	if (*line)
		return (false);
	return (true);
}
