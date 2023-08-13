/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:13:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 15:17:28 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

void	printerror(const char *msg, const char *sp);
int		open_file(const char *arg);
void	*ft_malloc(size_t count, size_t size);
char	*join_char(char *str, char c);
char	*substr_line(char *line);
void	print_infos(t_game *game);
void	print_map(char **map, int x, int y);
void	free_game(t_game *game);
double	ft_rad(float deg);
void  put_pixel_in_img(t_test *T, int x, int y,int color);


#endif