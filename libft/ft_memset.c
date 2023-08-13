/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:25:20 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/26 20:09:55 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*str;
	unsigned int		i;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
		str[i ++] = (unsigned char)c;
	b = (void *) str;
	return (b);
}
