/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:58:09 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 14:59:16 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../include/utils.h"

typedef struct s_lexer
{
	char			*src;
	unsigned int	i;
	char			c;
	size_t			size;
}	t_lexer;

t_game	*init_attr(void);

t_lexer	*init_lexer(char *line);
void	lexer_iter(t_lexer *lexer);
void	skip_whitespace(t_lexer *lexer);
void	free_lexer(t_lexer *lexer);

void	add_color(t_game *game, t_lexer *lexer);
void	set_color(long *color, t_lexer *lexer);
void	get_color(int color[], char *nb, int i);
char	*get_color_str(t_lexer *lexer);

int		rgb_to_dec(int color[]);

void	add_textures(t_game *game, t_lexer *lexer);
char	*join_dir(t_lexer *lexer);
void	get_textures(t_game *game, char *type, char *path);
void	set_path(void **texture, char *str, char *type);

t_game	*parsing(char *arg);
int		open_file(const char *arg);

void	check_firsts_infos(int fd, t_game *game);
void	add_infos(t_game *game, char *line);
void	check_fill_infos(t_game *game);

//map 

void	parse_map(int fd, t_game *game);
void	check_char(char *str, int *check);
void	check_charmap(t_list *list);
void	alloc_map(t_game *game, t_list *list);
t_list	*fill_list(int fd);
void	fill_map(t_game *game, t_list *list);

void	check_map(t_game *game);
void	check_walls(t_game *game);
void	dfs(t_game *game, int x, int y);

size_t	get_max(t_list *list);
t_pos	get_pos(t_game *game, char c);
t_game	*copy_game(t_game *game);

#endif