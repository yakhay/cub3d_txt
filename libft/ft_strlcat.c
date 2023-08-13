/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:52:16 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	len = i;
	if (dstsize == 0 || len > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i < dstsize - 1)
		dst[i ++] = src[j ++];
	dst[i] = '\0';
	return (ft_strlen(src) + len);
}
