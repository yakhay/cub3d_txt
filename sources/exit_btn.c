/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:43:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 00:18:06 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_echap(t_test *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(0);
}
int	ft_cross(t_test *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(0);
	return (0);
}
