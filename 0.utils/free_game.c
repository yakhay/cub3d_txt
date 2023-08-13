/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:53 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:37:03 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.m)
	{
		while (game->map.m[i])
			free(game->map.m[i++]);
		free(game->map.m);
	}
	if (game->txt.no.img)
		free(game->txt.no.img);
	if (game->txt.so.img)
		free(game->txt.so.img);
	if (game->txt.we.img)
		free(game->txt.we.img);
	if (game->txt.ea.img)
		free(game->txt.ea.img);
	if (game->mlx.mlx && game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	
	free(game);
}
