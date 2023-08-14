/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:03:20 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 00:03:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/cub3D.h"


int	draw_element(t_test *test, float tile_x, float tile_y)
{
	int	y;
	int	x;

	x = floor(tile_x / MINI_T);
	y = floor(tile_y / MINI_T);
	if (x < 0 || y < 0 
	||  x >= test->c_len || y >= test->r_len )
		return (15528177);
	else if (test->map[y][x] == '1')
		return (6516338);
	else if (test->map[y][x] == ' ')
		return (15528177);
	return (14673641);
}

void	put_pixel(t_test *test, int x, int y, int color)
{
	char *add;

    add = test->mini->addr + (y * test->mini->line_length + x * (test->mini->bits_per_pixel / 8));
    *(int *)add = color;
}
void	draw_player(t_test *test)
{
	int	y;
	int	x;
	int	i;
	int	j;

	x = (MINI_W / 2) + 3;
	i = -1;
	while ( ++i < 5)
	{
		y = (MINI_H / 2)  + 3;
		j = -1;
		while (++j < 5)
			put_pixel(test, x + i, y + j, 0xB75242);
	}
}

void	mini_map(t_test *test)
{
	int i;
	int j;
	float tile_x;
	float tile_y;
	int color;
	
	tile_x = (test->px / 64 * MINI_T) - (MINI_W / 2) - 1;
	i = -1;
	while (++i < MINI_W)
	{
		j = -1;
		tile_y = (test->py / 64 * MINI_T) - (MINI_H / 2) -1;
		while ( ++j < MINI_H)
		{
			color = draw_element(test, tile_x, tile_y);
			put_pixel(test, i, j, color);
			tile_y ++;
		}
		tile_x ++ ;
	}
	draw_player(test);
}