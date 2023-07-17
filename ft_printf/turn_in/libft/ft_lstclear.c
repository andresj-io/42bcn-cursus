/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:52:52 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/15 19:26:17 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
