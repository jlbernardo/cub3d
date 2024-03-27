/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:52:45 by julberna          #+#    #+#             */
/*   Updated: 2023/05/28 02:44:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cache_s;

	i = 0;
	cache_s = (unsigned char *)s;
	if (n == '\0')
		return (NULL);
	while (i < n)
	{
		if (cache_s[i] == (unsigned char)c)
			return (&cache_s[i]);
		i++;
	}
	return (NULL);
}
