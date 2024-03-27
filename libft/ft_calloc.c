/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:42 by julberna          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:58 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		result;

	pointer = NULL;
	result = nmemb * size;
	if (!nmemb || !size || nmemb == result / size)
		pointer = malloc(result);
	if (pointer)
		while (result--)
			*(unsigned char *)(pointer + result) = 0;
	return (pointer);
}
