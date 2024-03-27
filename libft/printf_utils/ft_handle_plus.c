/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plus_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:19:22 by julberna          #+#    #+#             */
/*   Updated: 2023/07/11 16:18:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_int_bonus(long int n);

int	ft_handle_plus(va_list args)
{
	int			numbers_printed;
	long int	n;

	numbers_printed = 0;
	n = va_arg(args, int);
	if (n >= 0)
	{
		ft_putchar_fd('+', 1);
		numbers_printed++;
	}
	numbers_printed += ft_handle_int_bonus(n);
	return (numbers_printed);
}

static int	ft_handle_int_bonus(long int n)
{
	int			numbers_printed;

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
