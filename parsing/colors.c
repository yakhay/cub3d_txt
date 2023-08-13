/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:37:36 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:25:50 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_color(t_game *game, t_lexer *lexer)
{
	char	c;

	c = lexer->c;
	lexer_iter(lexer);
	if (lexer->c != ' ')
		printerror("No space sparate color", NULL);
	skip_whitespace(lexer);
	if (!lexer->c)
		printerror("No color set", NULL);
	if (c == 'F')
		set_color(&game->color.f, lexer);
	if (c == 'C')
		set_color(&game->color.c, lexer);
}

void	set_color(long *color, t_lexer *lexer)
{
	int		i;
	char	*nb;
	int		color_tmp[3];

	i = -1;
	if (*color != -1)
		printerror("Color already set", NULL);
	while (++i < 3 && lexer->c)
	{
		nb = get_color_str(lexer);
		if ((i < 2 && lexer->c != ',') || (i == 2 && lexer->c))
			printerror("Invalid color ", NULL);
		lexer_iter(lexer);
		get_color(color_tmp, nb, i);
	}
	if (i != 3)
		printerror("Invalid color", NULL);
	*color = rgb_to_dec(color_tmp);
}

void	get_color(int color[], char *nb, int i)
{
	color[i] = ft_atoi(nb);
	if (color[i] > 255 || (int)color[i] < 0)
		printerror("RGB color must be between 0 and 255", NULL);
	free(nb);
}

char	*get_color_str(t_lexer *lexer)
{
	char	*nb;
	int		j;

	j = -1;
	nb = NULL;
	skip_whitespace(lexer);
	while (!ft_strchr(",", lexer->c) && ft_isdigit(lexer->c) && ++j < 3)
	{
		nb = join_char(nb, lexer->c);
		lexer_iter(lexer);
	}
	skip_whitespace(lexer);
	return (nb);
}

int	rgb_to_dec(int color[])
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}
