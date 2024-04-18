/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:42:58 by julberna          #+#    #+#             */
/*   Updated: 2024/04/18 20:46:47 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strschr(const char *s, const char *set)
{
	int	i;
	int	j;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (s[i] == set[j])
				return ((char *)s + i);
		}
	}
	j = -1;
	while (set[++j])
	{
		if (set[j] == '\0' && s[i] == '\0')
			return ((char *)s + i);
	}
	return (NULL);
}
