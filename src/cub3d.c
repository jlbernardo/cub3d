/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:26:50 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/14 20:36:12 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	cub;

	parse(&cub, argc, argv);
	validation(&cub);
	init(&cub);
	game(&cub);
	over(&cub, EXIT_SUCCESS);
}
