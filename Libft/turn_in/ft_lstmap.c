/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:12:01 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/15 15:05:32 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	new = ft_lstnew(f(aux->content));
	if (!new)
		return (NULL);
	ft_lstdelone(lst, del);
	new->next = ft_lstmap(aux->next, f, del);
}
