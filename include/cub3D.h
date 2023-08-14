/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:05:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 04:12:49 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"

void	init_game(t_test *test);
void	init_raycast(t_test *test);
void	init_speed(t_test *test);
void	init_textures(t_test *game);
void	init_texture_fill(t_test *game,t_img *txt);


//hook


int		ft_cross(t_test *test);
void	ft_echap(t_test *test);


void  mov_up(t_test *test);
void mov_down(t_test *test);
void mov_rhit(t_test *test);
void mov_left(t_test *test);

int motion(t_test *test);
double ft_ray_x(t_test *info,float thet);
double ft_ray_y(t_test *info, float thet);

int	presse_key(int key, t_test *test);
int	relesse_key(int key, t_test *test);
int motion(t_test *test);
void ft_ray(t_test *test);

void  put_pixel_in_img(t_test *T, int x, int y,int color);
int getcolor(t_img *wall,int n);
void	mini_map(t_test *test);


void	draw_celling(t_test *test, int k, int *j);
void	draw_wall(t_test *test, int k, int *j, int dir);
void	draw_floor(t_test *test, int k, int j);
void	render(t_test *test);

#endif
