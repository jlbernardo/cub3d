/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:02:12 by julberna          #+#    #+#             */
/*   Updated: 2023/07/09 20:44:22 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_unsigned_fd(n / 10, fd);
		ft_putnbr_unsigned_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(48 + n, fd);
	}
}

int	ft_handle_unsigned_int(va_list args)
{
	int				numbers_printed;
	unsigned int	n;

	numbers_printed = 0;
	n = va_arg(args, unsigned int);
	ft_putnbr_unsigned_fd(n, 1);
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
