/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:53:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 15:21:21 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str, char *s)
{
	if (str && *str)
		free(*str);
	*str = NULL;
	if (s)
		free(s);
	return (NULL);
}

char	*ft_end(char **str, char *s)
{
	char	*st;

	if (s)
		free(s);
	st = *str;
	*str = NULL;
	if (st && st[0] == 0)
	{
		free(st);
		return (0);
	}
	return (st);
}

char	*ft_read(int fd, char **str)
{
	int		d;
	int		check;
	char	*s;

	d = 1;
	s = (char *) malloc(sizeof(char) +(BUFFER_SIZE * sizeof(char)));
	if (!s)
		return (ft_free(str, 0));
	while (d)
	{
		check = read(fd, s, BUFFER_SIZE);
		if (check == -1)
			return (ft_free(str, s));
		if (check == 0)
			return (ft_end(str, s));
		s[check] = '\0';
		if (ft_nl(s) != -1)
			d = 0;
		*str = ft_strjoin_nl(str, s);
		if (!*str)
			return (0);
	}
	free(s);
	return (ft_substring(str));
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (!str || ft_nl(str) == -1)
		return (ft_read(fd, &str));
	return (ft_substring(&str));
}
