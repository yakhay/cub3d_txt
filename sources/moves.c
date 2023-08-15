/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:04:33 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:46:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	mov_up(t_test *test, float t_rad)
{
	float	x;
	float	y;

	x = test->px;
	y = test->py;
	x += cos(t_rad) * SPEED_MOVE;
	y -= sin(t_rad) * SPEED_MOVE;
	if (is_can_move(test, x, y) == -1)
		return ;
	if (is_des_wall(test, x + 5 * (cos(t_rad) * SPEED_MOVE), y - 5
			* (sin(t_rad) * SPEED_MOVE)) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		test->px = x;
		test->py = y;
	}
}

void	mov_down(t_test *test, float t_rad)
{
	float	x;
	float	y;

	x = test->px;
	y = test->py;
	x -= cos(t_rad) * SPEED_MOVE;
	y += sin(t_rad) * SPEED_MOVE;
	if (is_can_move(test, x, y) == -1)
		return ;
	if (is_des_wall(test, (x - 2 *(cos(t_rad) * SPEED_MOVE)), (y + 2
				* (sin(t_rad) * SPEED_MOVE))) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		test->px = x;
		test->py = y;
	}
}

void	theta_new(t_test *test)
{
	if (test->theta < 0)
		test->theta = 360.0 + test->theta;
	if (test->theta >= 360)
		test->theta = test->theta - 360.0;
}

void	mov_rhit(t_test *test)
{
	float	t_rad;
	float	x;
	float	y;
	float	new_theta;

	theta_new(test);
	new_theta = test->theta - 90.0;
	if (new_theta < 0)
		new_theta = 360.0 + new_theta;
	x = test->px;
	y = test->py;
	t_rad = M_PI * new_theta / 180;
	x += cos(t_rad) * SPEED_MOVE;
	y -= sin(t_rad) * SPEED_MOVE;
	if (is_can_move(test, x, y) == -1)
		return ;
	if (is_des_wall(test, x + cos(t_rad)
			* SPEED_MOVE, y - sin(t_rad) * SPEED_MOVE) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		test->px = x;
		test->py = y;
	}
}

void	mov_left(t_test *test)
{
	float	t_rad;
	float	x;
	float	y;
	float	new_theta;

	theta_new(test);
	test->theta = test->theta - 360.0;
	new_theta = test->theta + 90;
	if (new_theta >= 360)
		new_theta = new_theta - 360.0;
	x = test->px;
	y = test->py;
	t_rad = M_PI * (new_theta) / 180;
	x += cos(t_rad) * SPEED_MOVE;
	y -= sin(t_rad) * SPEED_MOVE;
	if (is_can_move(test, x, y) == -1)
		return ;
	if (is_des_wall(test, x + cos(t_rad)
			* SPEED_MOVE, y - sin(t_rad) * SPEED_MOVE) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		test->px = x;
		test->py = y;
	}
}
