/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:32:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 10:06:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_game	*parsing(char *arg)
{
	int		fd;
	t_game	*game;

	fd = open_file(arg);
	game = init_attr();
	check_firsts_infos(fd, game);
	parse_map(fd, game);
	return (game);
}

t_game	*init_attr(void)
{
	t_game	*game;

	game = ft_malloc(1, sizeof(t_game));
	game->txt.no.img = NULL;
	game->txt.so.img = NULL;
	game->txt.we.img = NULL;
	game->txt.ea.img = NULL;
	game->color.f = -1;
	game->color.c = -1;
	return (game);
}
