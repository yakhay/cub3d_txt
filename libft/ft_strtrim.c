/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:35:46 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/27 00:36:08 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_skip(const char *set, const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check(s1[i], set))
			i ++;
		else
			return (i);
	}
	return (0);
}

static int	ft_skipback(const char *set, const char *s1)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_check(s1[i], set))
			i --;
		else
			return (++i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = ft_skip(set, s1);
	end = ft_skipback(set, s1);
	str = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
		str[i ++] = s1[start ++];
	str[i] = '\0';
	return (str);
}
