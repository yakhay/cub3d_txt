/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:50:41 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:32:12 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_textures(t_game *game, t_lexer *lexer)
{
	char	*str;
	char	*path;

	str = join_dir(lexer);
	if (lexer->c != SPACE)
		printerror("NO Sapce sparate texture path", lexer->src + lexer->i);
	skip_whitespace(lexer);
	if (!lexer->c)
		printerror("Path not found", NULL);
	path = lexer->src + lexer->i;
	if (ft_strlen(path) <= 4)
		printerror("Invalid texture path", path);
	if (ft_strncmp(".xpm", path + ft_strlen(path) - 4, 4) != 0)
		printerror("Invalid texture extension", path);
	get_textures(game, str, path);
}

char	*join_dir(t_lexer *lexer)
{
	char	*str;

	str = join_char(NULL, lexer->c);
	lexer_iter(lexer);
	if (!lexer->c || !ft_strchr("OAE", lexer->c))
		printerror("Invalid texture ", NULL);
	str = join_char(str, lexer->c);
	lexer_iter(lexer);
	return (str);
}

void	get_textures(t_game *game, char *type, char *path)
{
	if (ft_strncmp("NO", type, 2) == 0)
		set_path(&game->txt.no.img, path, type);
	else if (ft_strncmp("SO", type, 2) == 0)
		set_path(&game->txt.so.img, path, type);
	else if (ft_strncmp("WE", type, 2) == 0)
		set_path(&game->txt.we.img, path, type);
	else if (ft_strncmp("EA", type, 2) == 0)
		set_path(&game->txt.ea.img, path, type);
	free(type);
}

void	set_path(void **texture, char *str, char *type)
{
	if (*texture)
		printerror("texture already set for ", type);
	*texture = ft_strdup(str);
}
