/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:54:24 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/07 18:12:22 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include<unistd.h>
# include <mlx.h>
#include <math.h>
#include "libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int width;
int height;

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
	struct s_img *next;
} t_img;
// typedef struct s_test
// {
//     int i;
//     int j;
//     float theta;
//     int m_r;
//     int m_l;
//     int m_u;
//     int m_d;
//     float x;
//     float y;
//     int ox;
//     float px;
//     float py;
//     void *mlx_ptr;
//     void *mlx_win;
//     int rot_rhit;
// 	int rot_left;
//     t_img *imag;
//     char **map;
//     int oy;

// }    t_test;
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
    int ox;
    int px;
    int py;
    void *mlx_ptr;
    void *mlx_win;
    t_img *imag;
    char **map;
    int new_move;

}    t_test;

char	*get_next_line(int fd);
size_t	ft_strlene(const char *str);
char	*ft_strjoine(char *s1, char *s2);


void  mov_up(t_test *test);
void mov_down(t_test *test);
void mov_rhit(t_test *test);
void mov_left(t_test *test);


double ft_ray_x(t_test *info,float thet);
double ft_ray_y(t_test *info, float thet);
#endif
