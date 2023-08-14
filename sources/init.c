/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:16:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	init_game(t_test *test)
{
	test->mlx_ptr = mlx_init();
	test->mlx_win = mlx_new_window(test->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	test->imag = malloc(sizeof(t_img));
	test->mini = malloc(sizeof(t_img));
	test->imag->ptr = mlx_new_image(test->mlx_ptr, WIDTH, HEIGHT);
	test->imag->addr = mlx_get_data_addr(test->imag->ptr,
			&test->imag->bits_per_pixel,
			&test->imag->line_length, &test->imag->endian);
	test->mini->ptr = mlx_new_image(test->mlx_ptr, MINI_W, MINI_H);
	test->mini->addr = mlx_get_data_addr(test->mini->ptr,
			&test->mini->bits_per_pixel,
			&test->mini->line_length, &test->mini->endian);
	init_raycast(test);
	init_speed(test);
	init_textures(test);
	test->map = test->game->map.m;
}

void	init_raycast(t_test *test)
{
	char	d;

	d = test->game->p.v;
	if (d == 'E')
		test->theta = 0;
	else if (d == 'N')
		test->theta = 90;
	else if (d == 'W')
		test->theta = 180;
	else if (d == 'S')
		test->theta = 270;
	test->py = (test->game->p.x * TILE_S) + (TILE_S / 2);
	test->px = (test->game->p.y * TILE_S) + (TILE_S / 2);
	test->i = 0;
	test->j = 1;
	test->ox = 0;
	test->p_dst = (WIDTH / 2) / tan(ft_rad(FOV / 2));
	test->r_len = test->game->map.r_len;
	test->c_len = test->game->map.c_len;
}

void	init_speed(t_test *test)
{
	test->m_r = 0;
	test->m_l = 0;
	test->m_u = 0;
	test->m_d = 0;
	test->rot_rhit = 0;
	test->rot_left = 0;
}

void	init_textures(t_test *game)
{
	init_texture_fill(game, &game->game->txt.no);
	init_texture_fill(game, &game->game->txt.so);
	init_texture_fill(game, &game->game->txt.we);
	init_texture_fill(game, &game->game->txt.ea);
}

void	init_texture_fill(t_test *game,t_img *txt)
{
	char	*path;

	path = txt->ptr;
	txt->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&txt->width, &txt->heigth);
	if (!txt->ptr)
		printerror("Error while loading texture", NULL);
	txt->addr = mlx_get_data_addr(txt->ptr, &txt->bits_per_pixel,
			&txt->line_length, &txt->endian);
	free(path);
}
