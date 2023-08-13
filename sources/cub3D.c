/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:04:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/13 19:06:15 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void ft_init_image(t_test *test)
{
	test->wall1 = malloc(sizeof(t_img));
	test->wall2 = malloc(sizeof(t_img));
	test->wall3 = malloc(sizeof(t_img));
	test->wall4 = malloc(sizeof(t_img));

	test->wall1->ptr = mlx_xpm_file_to_image(test->mlx_ptr, "./textures/wall2.xpm",&test->wall1->width,&test->wall1->heigth);
	test->wall2->ptr = mlx_xpm_file_to_image(test->mlx_ptr, "./textures/wall2.xpm",&test->wall2->width,&test->wall2->heigth);
	test->wall3->ptr = mlx_xpm_file_to_image(test->mlx_ptr, "./textures/wall3.xpm",&test->wall3->width,&test->wall3->heigth);
	test->wall4->ptr = mlx_xpm_file_to_image(test->mlx_ptr, "./textures/img1.xpm",&test->wall4->width,&test->wall4->heigth);
	test->wall1->addr = mlx_get_data_addr(test->wall1->ptr, &test->wall1->bits_per_pixel,&test->wall1->line_length, &test->wall1->endian);
	test->wall2->addr = mlx_get_data_addr(test->wall2->ptr, &test->wall2->bits_per_pixel,&test->wall2->line_length, &test->wall2->endian);
	test->wall3->addr = mlx_get_data_addr(test->wall3->ptr, &test->wall3->bits_per_pixel,&test->wall3->line_length, &test->wall3->endian);
	test->wall4->addr = mlx_get_data_addr(test->wall4->ptr, &test->wall4->bits_per_pixel,&test->wall4->line_length, &test->wall4->endian);
}

int	main(int ac, char **av)
{
	t_game	*game;
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (ac != 2)
		printerror("Enter just 1 argument", NULL);
	game = parsing(av[1]);
	game->test = test;
	init_game(game);
	test->mlx_ptr = mlx_init();
	test->mlx_win = mlx_new_window(game->test->mlx_ptr,  WIDTH, HEIGHT, "cub3D");
	test->imag = malloc(sizeof(t_img));
	test->imag->ptr = mlx_new_image(test->mlx_ptr, WIDTH, HEIGHT );
	test->imag->addr = mlx_get_data_addr(test->imag->ptr, &test->imag->bits_per_pixel,
		&test->imag->line_length, &test->imag->endian);
	test->py = (game->p.x * TILE_S) + (TILE_S / 2);
	test->px = (game->p.y * TILE_S) + (TILE_S / 2);
	test->map = game->map.m;
	ft_init_image(test);
	//ft_ray(test);
  	mlx_hook(game->test->mlx_win, 2, 0,presse_key, test);
	mlx_hook(game->test->mlx_win, 3, 0,relesse_key, test);
	mlx_loop_hook(game->test->mlx_ptr, motion, test);
	mlx_loop(game->test->mlx_ptr);
	return (0);
}
