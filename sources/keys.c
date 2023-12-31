/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:03:49 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:09:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

int	presse_key(int key, t_test *test)
{
	if (key == 65363)
		test->rot_rhit = 1;
	if (key == 65361)
		test->rot_left = 1;
	if (key == 119)
		test->m_u = 1;
	if (key == 115)
		test->m_d = 1;
	if (key == 100)
		test->m_r = 1;
	if (key == 97)
		test->m_l = 1;
	if (key == 65307)
		ft_echap(test);
	return (0);
}

int	relesse_key(int key, t_test *test)
{
	if (key == 65363)
		test->rot_rhit = 0;
	if (key == 65361)
		test->rot_left = 0;
	if (key == 119)
		test->m_u = 0;
	if (key == 115)
		test->m_d = 0;
	if (key == 100)
		test->m_r = 0;
	if (key == 97)
		test->m_l = 0;
	return (0);
}

int	motion(t_test *test)
{
	if (test->m_r == 1)
		mov_rhit(test);
	if (test->m_l == 1)
		mov_left(test);
	if (test->m_u == 1)
		mov_up(test, test->theta / 180 * M_PI);
	if (test->m_d == 1)
		mov_down(test, test->theta / 180 * M_PI);
	if (test->rot_rhit == 1)
	{
		test->i = 1;
		test->theta -= SPEED_ROT;
		if (test->theta < 0)
			test->theta = 360.0 + test->theta;
	}
	if (test->rot_left == 1)
	{
		test->i = 1;
		test->theta += SPEED_ROT;
		if (test->theta >= 360)
			test->theta = test->theta - 360.0;
	}
	ft_ray(test);
	test->i = 0;
	return (0);
}
