/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:19:22 by julberna          #+#    #+#             */
/*   Updated: 2023/05/29 00:21:40 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cache_str;

	i = 0;
	cache_str = (unsigned char *)s;
	while (i < n)
	{
		cache_str[i] = c;
		i++;
	}
	return (cache_str);
}
