/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:56:41 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/27 19:39:40 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (!lst || !lst[0] || !del)
		return ;
	while (lst[0])
	{
		t = lst[0]->next;
		(*del)(lst[0]->content);
		free(lst[0]);
		lst[0] = t;
	}
	lst[0] = NULL;
}
