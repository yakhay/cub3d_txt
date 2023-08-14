/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 04:52:23 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:06:12 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	free_game(t_game *game)
{
	char	**m;
	int		i;

	i = -1;
	m = game->map.m;
	while (m && m[++i])
		free(m[i]);
	free(m);
	free(game);
}
