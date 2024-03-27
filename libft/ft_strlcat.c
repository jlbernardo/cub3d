/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:01:16 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:57 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	while (dest && dest[i] != '\0')
		i++;
	dest_len = i;
	i = 0;
	while (src && src[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (src && (dest_len + i + 1) < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
