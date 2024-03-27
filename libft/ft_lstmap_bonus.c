/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:19:15 by julberna          #+#    #+#             */
/*   Updated: 2023/05/28 22:33:57 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*buffer;

	map = NULL;
	while (lst && f && del)
	{
		buffer = ft_lstnew(f(lst->content));
		if (!buffer)
			ft_lstdelone(buffer, del);
		else
			ft_lstadd_back(&map, buffer);
		lst = lst->next;
	}
	return (map);
}
