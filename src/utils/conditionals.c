/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditionals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:35:52 by julberna          #+#    #+#             */
/*   Updated: 2024/04/15 21:50:44 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	is_alpha_numeric_line(char *line)
{
	while (*line && (is_space(*line) || ft_isalnum(*line)))
		line++;
	if (*line)
		return (false);
	return (true);
}
