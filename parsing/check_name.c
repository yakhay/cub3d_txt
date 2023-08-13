/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:36:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/02 14:10:16 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	open_file(const char *arg)
{
	int	fd;

	if (ft_strlen(arg) <= 4)
		printerror("Invalid name map", arg);
	if (ft_strncmp(".cub", arg + (ft_strlen(arg) - 4), 4) != 0)
		printerror("Inavlid file extension", arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:\n");
		exit(1);
	}
	return (fd);
}