/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:33:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:51:13 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	parse_map(int fd, t_game *game)
{
	t_list	*list;

	list = fill_list(fd);
	check_charmap(list);
	fill_map(game, list);
	check_map(game);
	ft_lstclear(&list, free);
}

void	check_charmap(t_list *list)
{
	int	check_p;

	check_p = 0;
	while (list)
	{
		if (list->content)
			check_char(list->content, &check_p);
		list = list->next;
	}
	if (!check_p)
		printerror("there is no player !!", NULL);
}

void	check_char(char *str, int *check)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("10 ", str[i]))
			continue ;
		else if (ft_strchr("NEWS", str[i]))
		{
			if (*check)
				printerror("there is more than 1 palyer", NULL);
			*check = 1;
		}
		else
			printerror("invalid character !!", NULL);
	}
}
