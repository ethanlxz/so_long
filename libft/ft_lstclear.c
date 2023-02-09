/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:59:34 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 16:11:03 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (temp)
	{
		del(temp->content);
		free(temp);
		temp = temp->next;
	}
	*lst = NULL;
}
