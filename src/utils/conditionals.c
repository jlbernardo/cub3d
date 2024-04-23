/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditionals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:35:52 by julberna          #+#    #+#             */
/*   Updated: 2024/04/23 15:59:51 by julberna         ###   ########.fr       */
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

int	count_tabs(char *str)
{
	int	i;
	int	total_tabs;

	i = 0;
	total_tabs = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			total_tabs++;
		i++;
	}
	return (total_tabs);
}
