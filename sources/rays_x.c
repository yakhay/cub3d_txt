/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:07:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:55:19 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

int	check_to_berk_posi(t_test *info, float y1, float x)
{
	float	y;
	int		i;
	int		j;

	y = info->py - y1;
	i = (int)(y / 64);
	j = (int)(info->px + x + 1) / 64;
	if (j >= info->c_len - 1 || j < 0 || i < 0 || i >= info->r_len - 1)
		return (0);
	if (info->map[i][j] == '1')
		return (0);
	else
		info->j++;
	return (1);
}

int	check_to_berk_niga(t_test *info, float y1, float x)
{
	float	y;
	int		i;
	int		j;

	y = info->py - y1;
	i = (int)(y / 64);
	j = (int)((info->px - x) / 64 -1);
	if (j >= info->c_len - 1 || j < 0 || i < 0 || i >= info->r_len - 1)
		return (0);
	if (info->map[i][j] == '1')
		return (0);
	else
		info->j++;
	return (1);
}

double	petay(float x, float y1)
{
	double	r;

	r = sqrt(pow(x, 2) + pow(y1, 2));
	if (r < 0)
		return (2147483647);
	return (r);
}

double	dest_x(t_test *info, float thet, float y1, float x)
{
	double	r;

	r = petay(x, y1);
	info->xx_pxel = info->px + cos(thet * M_PI / 180) * r;
	info->yx_pxel = info->py - sin(thet * M_PI / 180) * r;
	return (r);
}

double	ft_ray_x(t_test *info, float thet)
{
	float	y1;
	float	x;

	info->j = 1;
	while (1)
	{
		if (cos(thet * M_PI / 180) >= 0)
		{
			x = floor(((info->px / 64) + info->j)) * 64 - info->px;
			y1 = x * tan(thet * M_PI / 180);
			if (check_to_berk_posi(info, y1, x) == 0)
				break ;
		}
		else
		{
			x = info->px - floor((info->px / 64) - info->j + 1) * 64;
			y1 = x * tan((180 - thet) * M_PI / 180);
			if (check_to_berk_niga(info, y1, x) == 0)
				break ;
		}
	}
	return (dest_x(info, thet, y1, x));
}
