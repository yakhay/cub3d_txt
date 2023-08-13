/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:50:54 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/27 11:33:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst)
		return ;
	if (!lst[0])
		lst[0] = new;
	else
	{
		t = lst[0];
		while (t->next)
		{
			t = t->next;
		}
		t->next = new;
	}
}
