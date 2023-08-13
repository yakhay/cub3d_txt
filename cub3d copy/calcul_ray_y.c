#include "cub3d.h"

int check_to_berk_posi(t_test *info, float y1, float x)
{
	float y;

	y = info->py - y1;
	if ((int)(y/64) > 11 || (int)(info->px + x + 1)/64 >= 15)
		return (0);

	//printf("y %d \nx %d\n",(int)(y/64),(int)(info->px + x + 1)/64);
	if ((int)(y/64) >= 0 && info->map[(int)(y/64)][(int)(info->px + x + 1)/64] == '1')
		return (0);
	else
	{
		info->j++;
		if ((int)(y/64) < 0)
			return (0);
	}
	return (1);
}

int check_to_berk_niga(t_test *info, float y1, float x)
{
	float y;
	 y = info->py - y1;
	if ((int)(y/64) > 11)
		return (0);
	if ((int)(y/64) >= 0 && info->map[(int)(y/64)][(int)((info->px - x)/64 -1)] == '1')
		return (0);
	else
	{
		info->j++;
		if ((int)(y/64) < 0)
			return (0);
	}
	return (1);
}

double ft_ray_y(t_test *info, float thet)
{
    double r;
    float y1;
    float x;
    info->j = 1;
    while (1)
    {
       if (cos(thet * M_PI/180) >= 0)
       {
            x = floor(((info->px/64) + info->j)) * 64 - info->px;
            y1 = x * tan(thet * M_PI/180);
			if (check_to_berk_posi(info, y1, x) == 0)
				break;
       }
       else
       {
            x = info->px - floor((info->px/64) - info->j  + 1) * 64;
            y1 = x * tan((180 - thet) * M_PI/180);
			if (check_to_berk_niga(info, y1, x) == 0)
				break;
       }
    }
    r = sqrt(pow(x,2) + pow(y1,2));
    if (r < 0)
        r = 2147483647;
    return (r);
}
