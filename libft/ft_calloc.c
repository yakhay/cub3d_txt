/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:37:34 by yodahani          #+#    #+#             */
/*   Updated: 2022/11/10 12:40:32 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mycalloc;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	mycalloc = (char *)malloc(count * size);
	if (!mycalloc)
		return (NULL);
	ft_bzero(mycalloc, count * size);
	return ((void *)mycalloc);
}
