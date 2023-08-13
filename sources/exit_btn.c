/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:43:56 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 20:04:40 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_echap(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(0);
}
int	ft_cross(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(0);
	return (0);
}
