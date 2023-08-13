/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:14:18 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:32:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_firsts_infos(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		printerror("Empty Map!!", NULL);
	while (line && i < 6)
	{
		if (!*line)
		{
			free(line);
			break ;
		}
		else if (*line == '\n')
			free(line);
		else if (++i)
			add_infos(game, line);
		if (i < 6)
			line = get_next_line(fd);
	}
	check_fill_infos(game);
}

void	add_infos(t_game *game, char *line)
{
	t_lexer	*lexer;

	line = substr_line(line);
	lexer = init_lexer(line);
	skip_whitespace(lexer);
	if (lexer->c == '\0')
		printerror("Firsts information line with multiple space", lexer->src);
	if (ft_strchr("NSWE", lexer->c))
		add_textures(game, lexer);
	else if (ft_strchr("FC", lexer->c))
		add_color(game, lexer);
	else
		printerror("Invalid firsts information", NULL);
	free_lexer(lexer);
}

void	check_fill_infos(t_game *game)
{
	if (game->color.c == -1)
		printerror("Color of celling not set", NULL);
	if (game->color.f == -1)
		printerror("Color of floor not set", NULL);
	if (game->txt.ea.img == NULL)
		printerror("texture of EA not set", NULL);
	if (game->txt.no.img == NULL)
		printerror("texture of NO not set", NULL);
	if (game->txt.so.img == NULL)
		printerror("texture of SO not set", NULL);
	if (game->txt.we.img == NULL)
		printerror("texture of WE not set", NULL);
}
