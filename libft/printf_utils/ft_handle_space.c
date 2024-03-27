/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:19:00 by julberna          #+#    #+#             */
/*   Updated: 2023/07/13 15:33:26 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_int_bonus(long int n);
static int	ft_handle_str_bonus(char *str);

int	ft_handle_space(va_list args, char specifier)
{
	int			numbers_printed;
	long int	n;
	char		*str;

	numbers_printed = 0;
	if (specifier == 'i')
	{
		n = va_arg(args, int);
		if (n >= 0)
		{
			ft_putchar_fd(' ', 1);
			numbers_printed += ft_handle_int_bonus(n) + 1;
		}
		else
			numbers_printed += ft_handle_int_bonus(n);
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		numbers_printed += ft_handle_str_bonus(str);
	}
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

static int	ft_handle_str_bonus(char *str)
{
	int		len;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		return (len);
	}
}
