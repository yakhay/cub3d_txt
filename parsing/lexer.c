/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:21:30 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 08:34:50 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/parsing.h"

t_lexer	*init_lexer(char *line)
{
	t_lexer	*lexer;

	lexer = ft_malloc(1, sizeof(t_lexer));
	lexer->i = 0;
	lexer->size = ft_strlen(line);
	lexer->src = line;
	lexer->c = lexer->src[0];
	return (lexer);
}

void	lexer_iter(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < lexer->size)
	{
		lexer->i ++;
		lexer->c = lexer->src[lexer->i];
	}
}

void	skip_whitespace(t_lexer *lexer)
{
	while (lexer->c && ft_strchr(" \n", lexer->c))
		lexer_iter(lexer);
}
void	free_lexer(t_lexer *lexer)
{
	free(lexer->src);
	free(lexer);
}
