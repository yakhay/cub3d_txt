/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:05:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 15:02:13 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"

void	init_game(t_game *game);
void	init_textures(t_game *game);
void	init_raycast(t_game *game);
void	init_speed(t_game *game);

void	init_texture_fill(t_game *game, void **txt);


//hook


int		ft_cross(t_game *game);
void	ft_echap(t_game *game);


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
#endif