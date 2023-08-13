/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:49:14 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/09 15:34:52 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void  put_pixel_in_img(t_test *T, int x, int y,int color)
{
    char *add;

    if (x < 0 || x >= width || y < 0 || y >= height)
        return ;
    add = T->imag->addr + (y * T->imag->line_length + x * (T->imag->bits_per_pixel / 8));
    *(int *)add = color;
}

void ft_ray(t_test *test)
{
    double r;
    float ry,rx;
    float Height_wall;
    int start;
    int j = 0;
    float alpha;;
    int k = 0;
    int x_ray,y_ray;
    
    alpha = test->theta + 30;
    if (alpha >= 360)
        alpha = alpha - 360.0;
    while (k < width)
    {
        if (alpha < 0)
            alpha = alpha + 360.0;
        if (alpha >= 360.0)
            alpha =  alpha - 360.0;
        x_ray = 0;
        y_ray= 0;
        rx = ft_ray_x(test,alpha);
        ry = ft_ray_y(test,alpha);
        if (rx > ry)
        {
          r = ry;
          y_ray = 1;
        }
        else
        {
            r = rx;
            x_ray = 1;
        }
        r = cos((alpha - test->theta) * M_PI/180) * r;
        Height_wall = (64 / r) * 600;
        start = (height - Height_wall) / 2;
        if (start < 0)
            start = 0;
        j = 0;
        while (j < start)
        {
            put_pixel_in_img(test, k, j,0x09DAF7);
            j++;
        }
        while(j < start + Height_wall)
        {
            if (alpha <= 90 && alpha > 0 && x_ray == 1)
                put_pixel_in_img(test, k, j,0x0B742B6);
            else if (alpha <= 90 && alpha > 0 && y_ray == 1)
                 put_pixel_in_img(test, k, j,0x4246B7);
            else if (alpha > 90 && alpha <= 180 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB742B6);
            else if (alpha > 90 && alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 180 && alpha <= 270 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 180 && alpha <= 270 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 270 && alpha <= 360 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 270 && alpha <= 360 && y_ray == 1)
                put_pixel_in_img(test, k, j,0x4246B7);
            j++;
        }
        while(j < height)
        {
            put_pixel_in_img(test, k, j,0xF39C12);
            j++;
        }
        k++;
        alpha -= 60.00 / width;
    }
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win, 
    test->imag->ptr, 0, 0);
}

// int key_hook(int key, t_test *test)
// {
//      if (key == 124)
//      {
// 		test->theta -= 10;
//         if (test->theta < 0)
//             test->theta = 360.0 + test->theta;
//      }
// 	if (key == 123)
//     {
// 		test->theta += 10;
//         if (test->theta >= 360)
//             test->theta = test->theta - 360.0;
//     }
// 	if (key == 13)
// 		mov_up(test);
// 	if (key == 1)
// 		mov_down(test);
// 	if (key == 2)
// 		mov_rhit(test);
// 	if (key == 0)
// 		mov_left(test);
// 	if (key == 53)
// 		exit(0);
//     mlx_clear_window(test->mlx_ptr, test->mlx_win);
//     ft_ray(test);
// 	return (0);
// }

int motion(t_test *test)
{
    if (test->m_r == 1)
	    mov_rhit(test);
    if (test->m_l == 1)
	    mov_left(test);
    if (test->m_u == 1)
	    mov_up(test);
    if (test->m_d == 1)
	    mov_down(test);
    if (test->rot_rhit == 1)
    {
        test->theta -= 4;
        if (test->theta < 0)
            test->theta = 360.0 + test->theta;
    }
    if (test->rot_left == 1)
    {
		test->theta += 4;
        if (test->theta >= 360)
            test->theta = test->theta - 360.0;
    }
   ft_ray(test);
	return (0);
}

int	relesse_key(int key, t_test *test)
{
	if (key == 124)
		test->rot_rhit = 0;
	if (key == 123)
		test->rot_left = 0;
	if (key == 13)
		test->m_u = 0;
	if (key == 1)
		test->m_d = 0;
	if (key == 2)
		test->m_r = 0;
	if (key == 0)
		test->m_l = 0;
	return (0);
}

int	presse_key(int key, t_test *test)
{
	if (key == 124)
		test->rot_rhit = 1;
	if (key == 123)
		test->rot_left = 1;
	if (key == 13)
		test->m_u = 1;
	if (key == 1)
		test->m_d = 1;
	if (key == 2)
		test->m_r = 1;
	if (key == 0)
		test->m_l = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
    char *line;
    char *map_line;
    t_test *T;
   
    T = malloc(sizeof(t_test));
     T->imag = malloc(sizeof(t_img));
    (void)ac;
    int fd = open(av[1], O_RDWR);
    
    T->theta = 270;
    T->px = 98;
    T->py = 98;
    T->i = 0;
    T->j = 1;
    T->ox = 0;
    width = 800;
    height = 600;
    T->m_r = 0;
	T->m_l = 0;
	T->m_u = 0;
	T->m_d = 0;
	T->rot_rhit = 0;
	T->rot_left = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        map_line = ft_strjoine(map_line,line);
        free(line);
    }
    T->map = ft_split(map_line,'\n');
    T->mlx_ptr = mlx_init();
    T->mlx_win = mlx_new_window(T->mlx_ptr, width, height, "CUB3D");
    T->imag->ptr = mlx_new_image(T->mlx_ptr, width, height);
	T->imag->addr = mlx_get_data_addr(T->imag->ptr, &T->imag->bits_per_pixel,
		&T->imag->line_length, &T->imag->endian);
   //ft_ray(T);
   //mlx_hook(T->mlx_win, 2, 0, key_hook, T);
    mlx_hook(T->mlx_win, 2, 0,presse_key, T);
    mlx_hook(T->mlx_win, 3, 0,relesse_key, T);
    mlx_loop_hook(T->mlx_ptr, motion, T);
    mlx_loop(T->mlx_ptr);
}
