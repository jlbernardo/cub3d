/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:15:02 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 19:56:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_game *cub, int argc, char **argv)
{
	check_input(cub, argc, argv);
	get_texture_path(cub);
	get_colors(cub);
	get_map(cub);
	get_player_direction(cub);
}

void	check_input(t_game *cub, int argc, char **argv)
{
	if (argc != 2)
		cuberror("Wrong number of arguments.", cub);
	ft_bzero(cub, sizeof(t_game));
	cub->map_path = argv[1];
	cub->map_data.raw_data = get_raw_data(cub->map_path);
}
