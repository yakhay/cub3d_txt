/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/12 13:43:21 by yakhay           ###   ########.fr       */
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

# include <mlx.h>
# include <stdio.h>
#include <math.h>
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


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_data_txt;

typedef struct s_texture
{
	t_data_txt					no;
	t_data_txt					so;
	t_data_txt					we;
	t_data_txt					ea;
}	t_texture;

typedef struct map
{
	char						**m;
	size_t						r_len;
	size_t						c_len;
}	t_map;

typedef struct s_speed
{
	int 	m_r;
	int 	m_l;
	int 	m_u;
	int 	m_d;
	int 	rot_rhit;
	int 	rot_left;
} t_speed;

typedef struct s_ray
{
    int 	i;
    int 	j;
    float 	theta;

    float 	x;
    float 	y;
	float 	alpha;
    int		ox;
	double	r;
	float	ry;
	float	rx;
	float	h_wall;
	float	dist_p;
	int		start_wall;
	int		end_wall;
	char	dir;
} t_ray;

typedef struct s_img
{
	char	dir;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
	char	*addr;
	void	*ptr;
} t_img;

typedef struct s_test
{
    int m_r;
	int m_l;
	int m_u;
	int m_d;
	int rot_rhit;
	int rot_left;
    int i;
    int j;
    float theta;
    float x;
    float y;
	float	d_x;
	float	d_y;
    int ox;
    int px;
    int py;
    void *mlx_ptr;
    void *mlx_win;
    t_img *imag;
    char **map;
    int new_move;
	int r_len;
	int	c_len;
	t_img *wall1;
	t_img *wall2;
	t_img *wall3;
	t_img *wall4;

	float xx_pxel;
	float yx_pxel;
	
	float xy_pxel;
	float yy_pxel;
}    t_test;


typedef struct s_game
{
	t_mlx						mlx;
	t_pos						p;
	t_speed						speed;
	t_ray						ray;
	t_color						color;
	t_texture					txt;
	t_map						map;
	t_data_txt					screen;
	t_test						*test;
}	t_game;


#endif
