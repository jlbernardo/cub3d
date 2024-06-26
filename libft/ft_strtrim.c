/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:16:38 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 19:58:51 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[size - 1]) && size)
		size--;
	trimmed = ft_calloc(size + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1, size + 1);
	return (trimmed);
}
