/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:47:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:05:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	alloc_map(t_game *game, t_list *list)
{
	size_t	i;

	i = -1;
	game->map.c_len = get_max(list);
	game->map.r_len = ft_lstsize(list);
	game->map.m = ft_malloc(game->map.r_len + 1, sizeof(char *));
	while (++i < game->map.r_len)
	{
		game->map.m[i] = ft_malloc(game->map.c_len + 1, sizeof(char));
		ft_memset(game->map.m[i], ' ', game->map.c_len);
		game->map.m[i][game->map.c_len] = '\0';
	}
	game->map.m[i] = NULL;
}

char	*skip_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		printerror(" NO  map", NULL);
	return (line);
}

t_list	*fill_list(int fd)
{
	char	*line;
	t_list	*list;

	list = NULL;
	line = skip_nl(fd);
	while (line)
	{
		line = substr_line(line);
		if (line)
		{
			check_char(line, NULL);
			ft_lstadd_back(&list, ft_lstnew(line));
		}
		else
			printerror("Empty line in the map", NULL);
		line = get_next_line(fd);
	}
	return (list);
}

void	fill_map(t_game *game, t_list *list)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	alloc_map(game, list);
	while (list)
	{
		i = -1;
		s = list->content;
		if (s && *s)
		{
			while (s[++i])
				game->map.m[j][i] = s[i];
		}
		list = list->next;
		j++;
	}
}
