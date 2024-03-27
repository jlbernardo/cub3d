/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:01:40 by julberna          #+#    #+#             */
/*   Updated: 2023/07/09 20:34:12 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_int(va_list args)
{
	int			numbers_printed;
	long int	n;

	n = va_arg(args, int);
	numbers_printed = 0;
	ft_putnbr_fd(n, 1);
	if (n <= 0)
	{
		numbers_printed++;
		n = -n;
	}
	while (n > 0)
	{
		numbers_printed++;
		n /= 10;
	}
	return (numbers_printed);
}
