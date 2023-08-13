/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:35:50 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/23 14:43:35 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char) c;
	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == cc)
			return (str + i);
		i++;
	}
	return (0);
}
