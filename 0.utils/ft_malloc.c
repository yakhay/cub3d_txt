/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:09:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 15:13:04 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	*ft_malloc(size_t count, size_t size)
{
	void	*allocated;

	allocated = ft_calloc(count, size);
	if (!allocated)
	{
		perror("Error\n");
		exit(1);
	}
	return (allocated);
}