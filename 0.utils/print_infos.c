/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:34:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/08 20:27:08 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == x && j == y)
				printf("\033[0;31m%c\033[0m", map[i][j]);
			else
				printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i ++;
	}
}

void	print_ray(t_game *game)
{
	t_ray	*ray;
	
	ray = &game->ray;
	printf("Ray x = %f, y = %f\n", ray->x, ray->y);
	printf("Ray i = %d, j = %d\n", ray->i, ray->j);
	printf("theta = %f\n", ray->theta);
	printf("Ray x = %f, y = %f\n", ray->x, ray->y);
	printf("Ray %f\n", ray->r);
	printf("DST %f\n", ray->dist_p);
	
}

void	print_infos(t_game *game)
{
	int	j;

	j = 0;
	printf("Celling color:  %ld\n", game->color.c);
	printf("Floor color:  %ld\n", game->color.f);
	printf("texture NO:  %s\n", game->txt.no.img);
	printf("texture SO:  %s\n", game->txt.so.img);
	printf("texture WE:  %s\n", game->txt.we.img);
	printf("texture EA:  %s\n", game->txt.ea.img);
	printf("MAP len [%ld]\n", game->map.r_len);
	printf("MAP width [%ld]\n", game->map.c_len);
	print_map(game->map.m, -1, -1);
	print_ray(game);
	
}
