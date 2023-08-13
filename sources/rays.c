/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:05:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/13 19:09:15 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "../include/cub3D.h"

void  put_pixel_in_img(t_test *T, int x, int y,int color)
{
    char *add;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    add = T->imag->addr + (y * T->imag->line_length + x * (T->imag->bits_per_pixel / 8));
    *(unsigned int*)add = color;
}

int getcolor(t_img *wall,int n,int Height_wall,int start, float m)
{
    char    *add;
	(void)Height_wall;
	(void)start;
    // float   n = ((float)(j - start) / Height_wall) * wall->heigth;
    //printf("%f, %f \n",n,m);

    if (n >= wall->heigth || n < 0 || m >= wall->width || n < 0)
        return (0);
    add = wall->addr + (int)n * wall->line_length + (int)m * (wall->bits_per_pixel / 8);
    return (*(unsigned int*)add);
}

void ft_ray(t_test *test)
{
    float r;
    float ry,rx,h;
    float Height_wall;
    int start;
    int j = 0;
    float alpha;
    int k = 0;
    int x_ray,y_ray;

    alpha = test->theta + 30;
    if (alpha >= 360)
        alpha = alpha - 360.0;

    while (k < WIDTH)
    {
        if (alpha < 0)
            alpha = alpha + 360.0;
        if (alpha >= 360.0)
            alpha =  alpha - 360.0;
        x_ray = 0;
        y_ray= 0;
        ry = ft_ray_y(test,alpha);
        rx = ft_ray_x(test,alpha);
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
        r = cos((alpha - test->theta) * M_PI/180) * r;
        Height_wall = (64 / r) * 277;
        start = (HEIGHT - Height_wall) / 2;
        if (start < 0)
            start = 0;
        j = 0;
        while (j < start)

           put_pixel_in_img(test, k, j++, 0x09DAF7);
       float   m = (fmod(test->xy_pxel, 64) / 64) * test->wall1->width;

        {
            put_pixel_in_img(test, k, j,0x09DAF7);
            j++;
        }
		h = 0;
		if (Height_wall > HEIGHT)
			h = test->wall1->heigth / Height_wall * ((Height_wall - HEIGHT) / 2);
        while(j < start + Height_wall)
        {
            if (alpha <= 90 && alpha > 0 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(test->wall1,h, Height_wall,start,m));
            else if (alpha > 90 && alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j, getcolor(test->wall1,h, Height_wall,start,m));
            else
                put_pixel_in_img(test, k, j, 0xB05200);
            j++;
			h += test->wall1->heigth / Height_wall;
          }
        while(j < HEIGHT)
        {
            put_pixel_in_img(test, k, j, 0xB75242);
            j++;
        }
        k++;
        alpha -= 60.00 / WIDTH;
    }
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win,
    test->imag->ptr, 0, 0);
}
