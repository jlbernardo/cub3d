/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:33:55 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/27 20:36:15 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check(t_game *cub, int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Wrong number of arguments.\n", 27);
		exit(EXIT_FAILURE);
	}
	ft_bzero(cub, sizeof(t_game));
	cub->map_path = argv[1];
}
