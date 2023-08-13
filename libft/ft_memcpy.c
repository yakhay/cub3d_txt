/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:04:10 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/10 13:31:48 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	if (!src && !dst)
		return (0);
	if (src == dst)
		return ((void *)dst);
	i = 0;
	src1 = (char *) src;
	dst1 = (char *) dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i ++;
	}
	return ((void *)dst1);
}
