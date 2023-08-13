/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:41:31 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:46:08 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_map(t_game *game)
{
	t_game	*game_copy;

	game->p = get_pos(game, '\0');
	game_copy = copy_game(game);
	check_walls(game_copy);
	free_game(game_copy);
}

void	check_walls(t_game *game)
{
	t_pos	p;

	dfs(game, game->p.x, game->p.y);
	p = get_pos(game, '0');
	while (p.x != -1)
	{
		dfs(game, p.x, p.y);
		p = get_pos(game, '0');
	}
}

void	dfs(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)game->map.r_len || y >= (int) game->map.c_len)
	{
		printf("x = %d, y = %d\n", x, y);
		print_infos(game);
		printerror("The map must be closed/surrounded by walls !!", NULL);
	}
	else if (game->map.m[x][y] == '1' || game->map.m[x][y] == '2')
		return ;
	else if (game->map.m[x][y] == ' ')
		printerror("The map must be closed/surrounded by walls !!", NULL);
	game->map.m[x][y] = '2';
	dfs(game, x, y - 1);
	dfs(game, x, y + 1);
	dfs(game, x - 1, y);
	dfs(game, x + 1, y);
}
