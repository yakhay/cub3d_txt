/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:53:24 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/14 04:12:35 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_celling(t_test *test, int k, int *j)
{
	 *j = 0;
	while (*j < test->start)
		put_pixel_in_img(test, k, (*j)++,  test->game->color.c);
}

void	draw_wall(t_test *test, int k, int *j, int dir)
{
	float	h;

	h = 0;
	if (test->h_wall > HEIGHT)
	h = dir/ test->h_wall * ((test->h_wall - HEIGHT) / 2);

	while(*j < test->start + test->h_wall)
	{
	if (test->v_or_h == 'h' && test->alpha < 180 && test->alpha > 0)
	put_pixel_in_img(test, k, *j, getcolor(&test->game->txt.no,h ));

	else if (test->v_or_h == 'v' && test->alpha <= 270 && test->alpha > 90)
	put_pixel_in_img(test, k, *j, getcolor(&test->game->txt.we,h));
	else if (test->v_or_h == 'h' && test->alpha > 180 && test->alpha <= 360)
	put_pixel_in_img(test, k, *j, getcolor(&test->game->txt.so,h ));
	else
	put_pixel_in_img(test, k, *j, getcolor(&test->game->txt.ea,h));
		(*j)++;
		h += dir/ test->h_wall;
	}
}
void	draw_floor(t_test *test, int k, int j)
{
	while(j < HEIGHT)
		put_pixel_in_img(test, k, j ++, test->game->color.f);
}

void	render(t_test *test)
{
	mini_map(test);
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
    test->imag->ptr, 0, 0);
     mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
    test->mini->ptr, 10, 10);
}
