/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:01:50 by julberna          #+#    #+#             */
/*   Updated: 2023/07/09 21:06:48 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base(unsigned long int nbr, char *base);

int	ft_handle_lower_hex(va_list args)
{
	int					chars_printed;
	unsigned long int	nbr;

	nbr = va_arg(args, unsigned int);
	if (nbr <= 0)
	{
		chars_printed = 1;
		nbr = -nbr;
	}
	chars_printed = ft_putnbr_base(nbr, "0123456789abcdef");
	return (chars_printed);
}

static void	ft_print_array(unsigned long int *inverter, int i)
{
	while (i > 0)
	{
		write(1, &inverter[i - 1], 1);
		i--;
	}
}

static int	ft_nbrlen(unsigned long int nbr)
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

static int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	int						base_len;
	int						rest;
	int						i;
	unsigned long int		*inverter;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		i++;
		return (i);
	}
	inverter = ft_calloc(ft_nbrlen(nbr), sizeof(unsigned long int));
	while (nbr > 0)
	{
		rest = nbr % base_len;
		nbr = nbr / base_len;
		inverter[i] = base[rest];
		i++;
	}
	ft_print_array(inverter, i);
	free(inverter);
	return (i);
}
