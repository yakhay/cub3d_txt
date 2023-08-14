/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:04:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:08:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	mouse_mv(int x, int y, t_test *test)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		if (x > test->x_m)
			test->theta += 4;
		else
			test->theta -= 4;
		test->x_m = x;
		test->y_m = y;
	}
	return (0);
}

int	print(int key , t_test *test)
{
	(void)test;
	printf("%d\n",key);
	return (1);
}
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
	mlx_hook(test->mlx_win, 2, 1L << 0, presse_key, test);
	mlx_hook(test->mlx_win, 3, 1L << 1, relesse_key, test);
	mlx_hook(test->mlx_win, 17, 0, ft_cross, test);
	mlx_hook(test->mlx_win, 6, 1L << 6, mouse_mv, test);
	mlx_loop_hook(test->mlx_ptr, motion, test);
	mlx_loop(test->mlx_ptr);
	return (0);
}
