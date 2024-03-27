/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:39:39 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 16:55:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_write_number(int i, long int num, int negative, char *str)
{
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		num = -num;
	return (num);
}

long int	ft_atol(const char *nptr)
{
	int		i;
	int		num;
	int		negative;
	char	*str;

	i = 0;
	negative = 0;
	num = 0;
	str = (char *)nptr;
	return (ft_write_number(i, num, negative, str));
}
