/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:02:01 by julberna          #+#    #+#             */
/*   Updated: 2023/07/09 20:13:31 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base(unsigned long nbr, char *base);

int	ft_handle_ptr(va_list args)
{
	int				chars_printed;
	unsigned long	nbr;

	nbr = va_arg(args, unsigned long);
	if (nbr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		chars_printed = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		chars_printed = 2;
		chars_printed = ft_putnbr_base(nbr, "0123456789abcdef");
	}
	return (chars_printed);
}

static void	ft_print_array(unsigned long *inverter, int i)
{
	while (i > 0)
	{
		write(1, &inverter[i - 1], 1);
		i--;
	}
}

static int	ft_nbrlen(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int					base_len;
	int					rest;
	int					i;
	unsigned long		*inverter;

	base_len = ft_strlen(base);
	i = 0;
	inverter = ft_calloc(ft_nbrlen(nbr) + 1, sizeof(unsigned long));
	while (nbr > 0)
	{
		rest = nbr % base_len;
		nbr = nbr / base_len;
		inverter[i] = base[rest];
		i++;
	}
	ft_print_array(inverter, i);
	free(inverter);
	return (i + 2);
}
