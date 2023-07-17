/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:02:40 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/15 13:47:19 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*aux;

	aux = lst;
	len = 0;
	while (aux->next)
	{
		len++;
		aux = aux->next;
	}
	return (len);
}