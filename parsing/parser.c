/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:32:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/13 23:40:52 by yodahani         ###   ########.fr       */
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
	game->txt.no.ptr = NULL;
	game->txt.so.ptr = NULL;
	game->txt.we.ptr = NULL;
	game->txt.ea.ptr = NULL;
	game->color.f = -1;
	game->color.c = -1;
	return (game);
}
