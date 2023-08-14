/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:04:33 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:12:09 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

int is_can_move(t_test *test,float t_rad, char c)
{
    int i;
    float x;
    float y;

    x =test->px;
    y =test->py;
    i = 0;
    if ((int)(y/64) >= test->r_len || (int)(x / 64) >= test->c_len)
        return (-1);
    if (c == '+')
    {
        while (i <= 10)
        {
            x += cos(t_rad) * i;
	        y -= sin(t_rad) * i;
            if (test->map[(int)y/64][(int)x/64] == '1')
                return (-1);
            i++;
        }
    }
    else
    {
         while (i <= 10)
        {
            x -= cos(t_rad) * i;
	        y += sin(t_rad) * i;
            if (test->map[(int)y/64][(int)x/64] == '1')
                return (-1);
            i++;
        }
    }
    return 0;
}

void  mov_up(t_test *test)
{
    float t_rad;
    float x;
    float y;

    x =test->px;
    y =test->py;


	t_rad = M_PI * test->theta / 180;
    if (is_can_move(test,t_rad,'+') == -1)
        return ;
	x += cos(t_rad) * 5;
	y -= sin(t_rad) * 5;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}
void mov_down(t_test *test)
{
    float t_rad;
    float x;
    float y;

    x =test->px;
    y =test->py;

	t_rad = M_PI * test->theta/ 180;
    if (is_can_move(test,t_rad,'-') == -1)
        return ;
	x -= cos(t_rad) * 5;
	y += sin(t_rad) * 5;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }

}
void mov_rhit(t_test *test)
{
    float t_rad;
    float x;
    float y;
    float new_theta;

    if (test->theta < 0)
        test->theta = 360.0 + test->theta;
    if (test->theta >= 360)
        test->theta = test->theta - 360.0;
    new_theta = test->theta - 90.0;
    if (new_theta < 0)
        new_theta = 360.0 + new_theta;
    x =test->px;
    y =test->py;
	t_rad = M_PI * new_theta / 180;
    if (is_can_move(test,t_rad,'+') == -1)
        return ;
	x += cos(t_rad) * 5;
	y -= sin(t_rad) * 5;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}

void mov_left(t_test *test)
{
    float t_rad;
    float x;
    float y;
    float new_theta;

    if (test->theta < 0)
            test->theta = 360.0 + test->theta;
    if (test->theta >= 360)
        test->theta = test->theta - 360.0;
    new_theta = test->theta + 90;
    if (new_theta >= 360)
        new_theta = new_theta - 360.0;
    x =test->px;
    y =test->py;
	t_rad = M_PI * (new_theta) / 180;
    if (is_can_move(test,t_rad,'+') == -1)
        return ;
	x += cos(t_rad) * 5;
	y -= sin(t_rad) * 5;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}
