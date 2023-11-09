/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:14:54 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/06 13:03:09 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*node_next;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		node_next = node->next;
		ft_lstdelone(node, del);
		node = node_next;
	}
	*lst = NULL;
}
