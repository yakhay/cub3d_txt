/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:05:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 01:34:58 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void ft_ray(t_test *test)
{
    float r;
    float ry,rx,h;
    float Height_wall;
    int start;
    int j = 0;
    int k = 0;
    int x_ray,y_ray;

    test->alpha =test->theta + 30;
    while (k < WIDTH)
    {
        if (test->alpha < 0)
            test->alpha = test->alpha + 360.0;
        if (test->alpha >= 360.0)
            test->alpha =  test->alpha - 360.0;
        x_ray = 0;
        y_ray= 0;
        ry = ft_ray_y(test,test->alpha);
        rx = ft_ray_x(test,test->alpha);
        if (ry > rx)
        {
            r = rx;
            x_ray = 1;
        }
        else
        {
            r = ry;
            y_ray = 1;
        }
        r *= cos((test->alpha - test->theta) * M_PI/180);
        Height_wall = (64 / r) * test->p_dst;
        start = (HEIGHT - Height_wall) / 2;
        if (start < 0)
            start = 0;
        j = 0;
        while (j < start)
           put_pixel_in_img(test, k, j++, 0x09DAF7);

       float   mn = (fmod(test->xy_pxel, 64) / 64) * test->game->txt.no.width;
       float   me = (fmod(test->yx_pxel, 64) / 64) * test->game->txt.no.width;
       float   ms = (fmod(test->xy_pxel, 64) / 64) * test->game->txt.no.width;
       float   mw = (fmod(test->yx_pxel, 64) / 64) * test->game->txt.no.width;

		h = 0;
		if (Height_wall > HEIGHT)
			h = test->game->txt.no.heigth / Height_wall * ((Height_wall - HEIGHT) / 2);
        while(j < start + Height_wall)
        {
            if (test->alpha <= 90 && test->alpha > 0 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.no,h ,mn));
            else if (test->alpha > 90 && test->alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.no,h ,mn));
                
            else if (test->alpha <= 90 && test->alpha > 0 && x_ray == 1)
                 put_pixel_in_img(test, k, j, getcolor(&test->game->txt.so,h ,me));
            else if (test->alpha >= 0 && test->alpha <= 270 && x_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.so,h ,me));
                
            else if (test->alpha > 180 && test->alpha <= 270 && x_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.we,h ,ms));
            else if (test->alpha > 270 && test->alpha == 0 && x_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.we,h ,ms));
                
            else if (test->alpha > 90 && test->alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.so,h ,mw));
            else if (test->alpha > 180 && test->alpha <= 270 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(&test->game->txt.so,h ,mw));
            j++;
			h += test->game->txt.no.heigth/ Height_wall;
          }
        while(j < HEIGHT)
        {
            put_pixel_in_img(test, k, j, 0xB75242);
            j++;
        }
        k++;
        test->alpha -= 60.00 / WIDTH;
    }

    mini_map(test);
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
    test->imag->ptr, 0, 0);
     mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
    test->mini->ptr, 10, 10);
}
