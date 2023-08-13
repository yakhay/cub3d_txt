/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:34:45 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/28 12:14:16 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*h;
	char			*n;

	h = (char *) haystack;
	n = (char *) needle;
	if (n[0] == '\0')
		return (h);
	if (!haystack && len == 0)
		return (NULL);
	i = 0;
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (h[i] == n[j] && i < len)
		{
			j ++;
			i ++;
			if (n[j] == '\0')
				return (h + (i - j));
		}
		i -= j - 1;
	}
	return (0);
}
