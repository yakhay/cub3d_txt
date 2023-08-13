/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:20:01 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/09 11:19:34 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int is_can_move(t_test *test)
{
    double x = ft_ray_x(test,test->theta);
    double y = ft_ray_y(test,test->theta);
    if (x > y)
        x = y;
    printf("%lf\n",x);
    if (x - 5 > 20)
        return (5);
    else if (x > 20)
        return (x - 20);
    return (-1);
}

void  mov_up(t_test *test)
{
    float t_rad;
    int move =is_can_move(test);
    if (move == -1)
        return ;

    float x =test->px,y =test->py;
	t_rad = M_PI * test->theta / 180;
	x += cos(t_rad) * move;
	y -= sin(t_rad) * move;
    //printf("%f\n",test->theta);
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
    float x =test->px,y =test->py;
	t_rad = M_PI * test->theta/ 180;
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

    float x =test->px,y =test->py;
	t_rad = M_PI * (test->theta - 90) / 180;
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
    float x =test->px ,y =test->py;
	t_rad = M_PI * (test->theta + 90) / 180;
	x += cos(t_rad) * 5;
	y -= sin(t_rad) * 5;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}
