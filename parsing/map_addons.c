/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_addons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:49:16 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:46:47 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

size_t	get_max(t_list *list)
{
	size_t	max;
	size_t	tmp;

	max = ft_strlen(list->content);
	while (list->next)
	{
		list = list->next;
		tmp = ft_strlen(list->content);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}

t_pos	get_pos(t_game *game, char c)
{
	t_pos		p;
	int			i;
	int			j;
	char		**m;

	m = game->map.m;
	j = -1;
	while (++j < (int)game->map.r_len)
	{
		i = -1;
		while (++i < (int)game->map.c_len)
		{
			if ((c && c == m[j][i]) || (!c && ft_strchr("WENS", m[j][i])))
			{
				p.x = j;
				p.y = i;
				p.v = m[j][i];
				return (p);
			}
		}
	}
	p.x = -1;
	p.y = -1;
	p.v = -1;
	return (p);
}

t_game	*copy_game(t_game *game)
{
	t_game		*copy_game;
	size_t		i;

	copy_game = ft_malloc(1, sizeof(t_game));
	copy_game->map.r_len = game->map.r_len;
	copy_game->map.c_len = game->map.c_len;
	copy_game->map.m = ft_malloc(game->map.r_len + 1, sizeof(char *));
	i = -1;
	while (++i < game->map.r_len)
		copy_game->map.m[i] = ft_strdup(game->map.m[i]);
	copy_game->map.m[i] = NULL;
	copy_game->p = game->p;
	return (copy_game);
}
