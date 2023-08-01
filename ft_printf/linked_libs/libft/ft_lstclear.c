/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:52:52 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 09:27:49 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		size;
	t_list	*next;

	if (!lst || !del)
		return ;
	size = ft_lstsize((*lst));
	while (size--)
	{
		next = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = next;
	}
}
