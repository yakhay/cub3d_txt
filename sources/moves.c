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

int	is_can_move(t_test *test, float x, float y)
{
	if ((int)(y / 64) >= test->r_len || (int)(x / 64) >= test->c_len)
		return (-1);
	if (test->map[(int)(test->py/ 64)][(int)(x/64)] != '1')
	{
		if (test->map[(int)(y/ 64)][(int)(test->px/64)] != '1')
		{
			if (test->map[(int)(test->py/ 64)][(int)(test->px/64)] != '1')
				return (0);
		}
	}
	return (-1);
}

int	is_des_wall(t_test *test, float x, float y)
{
	if ((int)(y / 64) >= test->r_len || (int)(x / 64) >= test->c_len)
		return (-1);
	if (test->map[(int)(test->py/ 64)][(int)(x/64)] != '1')
	{
				return (0);
	}
	return (-1);
}

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
	if (is_des_wall(test, x + cos(t_rad) * SPEED_MOVE, y - sin(t_rad) * SPEED_MOVE) == -1)
		return ;
	if (test->map[(int)y / 64][(int)x / 64] != '1')
	{
		test->i = 1;
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
	if (is_des_wall(test, (x - 2 *(cos(t_rad) * SPEED_MOVE)), (y + 2 * (sin(t_rad) * SPEED_MOVE))) == -1)
		return ;
	if (test->map[(int)y / 64][(int)x / 64] != '1')
	{
		test->i = 1;
		test->px = x;
		test->py = y;
	}
}

void	mov_rhit(t_test *test)
{
	float	t_rad;
	float	x;
	float	y;
	float	new_theta;

	if (test->theta < 0)
		test->theta = 360.0 + test->theta;
	if (test->theta >= 360)
		test->theta = test->theta - 360.0;
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
	if (is_des_wall(test, x + cos(t_rad) * SPEED_MOVE, y - sin(t_rad) * SPEED_MOVE) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		test->i = 1;
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

	if (test->theta < 0)
		test->theta = 360.0 + test->theta;
	if (test->theta > 360)
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
	if (is_des_wall(test, x + cos(t_rad) * SPEED_MOVE, y - sin(t_rad) * SPEED_MOVE) == -1)
		return ;
	if (test->map[(int)(y / 64)][(int)(x / 64)] != '1')
	{
		// test->i = 1;
		test->px = x;
		test->py = y;
	}
}
