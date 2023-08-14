/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 05:51:22 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define SPACE ' '
# define HEIGHT 600
# define WIDTH 800
# define TILE_S 64
# define RIGHT '-'
# define LEFT '+'
# define SPEED_MOVE 5
# define SPEED_ROT 5
# define FOV 60
# define MINI_W 200
# define MINI_H 100
# define MINI_T 12

# include <mlx.h>
# include <stdio.h>
#include <math.h>

typedef struct s_img
{
	char	*addr;
	void	*ptr;
	char	dir;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
	float	scale;
} t_img;


typedef struct s_pos
{
	int		x;
	int		y;
	int		v;
}	t_pos;

typedef struct set_color
{
	long						f;
	long						c;

}	t_color;




typedef struct s_texture
{
	t_img					no;
	t_img					so;
	t_img					we;
	t_img					ea;
}	t_texture;

typedef struct map
{
	char						**m;
	size_t						r_len;
	size_t						c_len;
}	t_map;


typedef struct s_game
{
	t_texture					txt;
	t_pos						p;
	t_color						color;
	t_map						map;
}	t_game;

typedef struct s_test
{
	float	alpha;
	char	v_or_h;
	float	h_wall;
	double	r;
	int		start;
    float	theta;
    int		m_r;
	int		m_l;
	int m_u;
	int m_d;
	int rot_rhit;
	int rot_left;
    int i;
    int j;
    int ox;
    int px;
    int py;
	float xx_pxel;
	float yx_pxel;
	float	p_dst;
	float xy_pxel;
	float yy_pxel;
	int r_len;
	int	c_len;
    char **map;
    t_img *mini;
    void *mlx_win;
    t_img *imag;
	int	x_m;
	int	y_m;
    void *mlx_ptr;
	t_game	*game;
}    t_test;




#endif
