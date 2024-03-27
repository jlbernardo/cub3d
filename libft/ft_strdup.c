/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:26:41 by julberna          #+#    #+#             */
/*   Updated: 2023/05/29 00:22:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupe;
	size_t	slen;

	slen = ft_strlen((char *)s);
	dupe = malloc(slen + 1);
	if (!dupe)
		return (NULL);
	ft_strlcpy(dupe, (char *)s, slen + 1);
	return (dupe);
}
