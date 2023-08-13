/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ray_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:55:02 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 10:55:13 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

int check_to_berk_posix(t_test *info, float x1, float y)
{
	float x;
	
	x = x1 + info->px;
	if ((int)(x/64) > 15)
		return (0);
	if ((int)(x/64) >= 0 &&  info->map[(int)((info->py - floor(y) - 1)/ 64)][(int)(x/64)] == '1')
		return (0) ;
	else
	{
		info->ox++;
		if ((int)((x)/64) < 0)
			return (0);
	}
	return (1);
}

int check_to_berk_nigax(t_test *info, float x1, float y)
{
	float x;
	
	 x = info->px - x1;
	if ((int)((x)/64) > 15)
		return (0);
	if ((int)((x)/64) >= 0 && info->map[(int)((info->py + floor(y) + 1)/ 64)][(int)((x)/64)] == '1')
		return (0);
		else
	{
		info->ox++;
		if ((int)((x)/64) < 0)
			return (0);
	}
	return (1);
}

double ft_ray_x(t_test *info,float thet)
{
    double r;
	float x1;
    float y;

    info->ox = 1;
    while (1)
    {
        if (sin(thet * M_PI/180) >= 0)
        {
            y = info->py - (floor((info->py / 64) - info->ox + 1) * 64);
            x1 = y / tan(thet * M_PI/180);
			if (check_to_berk_posix(info, x1, y) == 0)
				break ;
        }
        else
        {
            y = (floor((info->py / 64) + info->ox) * 64) - info->py;
            x1 = y / tan((thet - 180) * M_PI/180);
			if (check_to_berk_nigax(info, x1, y) == 0)
				break;
        }
    }
    r =sqrt(pow(x1,2) + pow(y,2));
    if (r < 0)
	{
        return (2147483647);
    }
    return (r);
}
