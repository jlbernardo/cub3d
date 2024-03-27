/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:42:30 by julberna          #+#    #+#             */
/*   Updated: 2023/05/28 02:45:00 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cache_s1;
	unsigned char	*cache_s2;

	i = 0;
	cache_s1 = (unsigned char *)s1;
	cache_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cache_s1[i] != cache_s2[i])
		{
			return (cache_s1[i] - cache_s2[i]);
		}
		i++;
	}
	return (0);
}
