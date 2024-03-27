/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:10:38 by julberna          #+#    #+#             */
/*   Updated: 2023/05/28 02:57:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cache_src;
	unsigned char	*cache_dest;

	cache_dest = (unsigned char *)dest;
	cache_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (cache_dest < cache_src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		cache_dest[n] = cache_src[n];
	}
	return (cache_dest);
}
