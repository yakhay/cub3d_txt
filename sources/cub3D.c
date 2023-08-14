/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:04:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:08:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (ac != 2)
		printerror("Enter just 1 argument", NULL);
	game = parsing(av[1]);
	test->game = game;
	init_game(test);
	ft_ray(test);
	mlx_hook(test->mlx_win, 2, 0, presse_key, test);
	mlx_hook(test->mlx_win, 3, 0, relesse_key, test);
	mlx_hook(test->mlx_win, 17, 0, ft_cross, test);
	mlx_loop_hook(test->mlx_ptr, motion, test);
	mlx_loop(test->mlx_ptr);
	return (0);
}
