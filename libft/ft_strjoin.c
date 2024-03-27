/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:28:29 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:43 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
		i++;
	s1_len = i;
	i = 0;
	while (s2 && s2[i] != '\0')
		i++;
	s2_len = i;
	joined = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (joined == NULL)
		return (NULL);
	ft_strlcat(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return ((char *)joined);
}
