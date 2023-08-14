/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:05:34 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:49:41 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	put_pixel_in_img(t_test *T, int x, int y, int color)
{
	char	*add;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	add = T->imag->addr + (y * T->imag->line_length
			+ x * (T->imag->bits_per_pixel / 8));
	*(unsigned int *)add = color;
}

int	getcolor(t_img *wall, int n)
{
	char	*add;

	if (n >= wall->heigth || n < 0
		|| wall->scale >= wall->width || wall->scale < 0)
		return (0x4246B7);
	add = wall->addr + (int)n * wall->line_length
		+ (int) wall->scale * (wall->bits_per_pixel / 8);
	return (*(unsigned int *)add);
}
