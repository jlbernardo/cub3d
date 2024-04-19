/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:42:58 by julberna          #+#    #+#             */
/*   Updated: 2024/04/18 21:02:25 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strschr(const char *s, const char *set)
{
	int	i;
	int	j;

	if (s == NULL || set == NULL)
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
	return (NULL);
}
