/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:05:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:26:22 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    calc_r(t_test *test)
{
    float   ry;
    float   rx;

    if (test->alpha < 0)
            test->alpha = test->alpha + 360.0;
    if (test->alpha > 360.0)
            test->alpha =  test->alpha - 360.0;
    ry = ft_ray_y(test,test->alpha);
    rx = ft_ray_x(test,test->alpha);
    if (ry > rx)
    {
        test->r = rx;
        test->v_or_h = 'v';
    }
    else
    {
        test->r = ry;
        test->v_or_h = 'h';
    }
    test->r *= cos((test->alpha - test->theta) * M_PI/180);
}

void    scale_txt(t_test *test)
{
	test->game->txt.no.scale = (fmod(test->xy_pxel, 64) / 64) * test->game->txt.no.width;
	test->game->txt.ea.scale = (fmod(test->yx_pxel, 64) / 64) * test->game->txt.ea.width;
	test->game->txt.so.scale = (fmod(test->xy_pxel, 64) / 64) * test->game->txt.so.width;
	test->game->txt.we.scale = (fmod(test->yx_pxel, 64) / 64) * test->game->txt.we.width;
}

int h_text(t_test *test)
{
    int dir;

	if (test->v_or_h == 'v' && test->alpha <= 270 && test->alpha > 90)
		dir = test->game->txt.we.heigth;
	else if (test->v_or_h == 'h' && test->alpha < 180 && test->alpha > 0)
		dir = test->game->txt.no.heigth;
	else if (test->v_or_h == 'v' && test->alpha > 180 && test->alpha <= 360)
		dir = test->game->txt.so.heigth;
	else
		dir = test->game->txt.ea.heigth;
	return (dir);
}

void ft_ray(t_test *test)
{
    int		j;
    int		k;
    int		dir;

	k = -1;
    test->alpha = test->theta + 30;
    while (++k < WIDTH)
    {
        calc_r(test);
        scale_txt(test);
		dir = h_text(test);
        test->h_wall = (64 / test->r) * test->p_dst;
        test->start = (HEIGHT - test->h_wall) / 2;
        if (test->start < 0)
            test->start = 0;
		draw_celling(test, k,&j);
		draw_wall(test, k, &j, dir);
		draw_floor(test, k, j);
	    test->alpha -= 60.00 / WIDTH;
    }
	render(test);
}
