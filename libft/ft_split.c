/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:42:12 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/10 15:18:47 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] == 0)
		return (0);
	if (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count ++;
		i ++;
	}
	if (s[i - 1] != c)
		count ++;
	return (count);
}

static char	**ft_freeme(char **str, int j)
{
	while (j >= 0)
		free(str[j --]);
	free (str);
	return (NULL);
}

int	ft_skip(char const *s, char c, int *i)
{
	int	j;

	while (s[*(i)] && s[*(i)] == c)
		(*i)++;
	j = *(i);
	while (s[j] && s[j] != c)
		j ++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;
	int		j;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **) malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && k < ft_count(s, c))
	{
		j = ft_skip(s, c, &i);
		if (j > i)
			str[k ++] = ft_substr(s, i, j - i);
		if (!str[k - 1])
			return (ft_freeme(str, k -2));
		i = j;
	}
	str[k] = NULL;
	return (str);
}
