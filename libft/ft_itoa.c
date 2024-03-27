/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:34:48 by julberna          #+#    #+#             */
/*   Updated: 2023/05/28 02:50:24 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_bytes(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			bytes;
	long int	ln;
	char		*str;

	ln = n;
	bytes = ft_count_bytes(ln);
	str = ft_calloc(bytes + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (ln < 0)
		ln = -ln;
	while (bytes > 0)
	{
		bytes--;
		str[bytes] = ln % 10 + '0';
		ln /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
