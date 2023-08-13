/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:30 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 08:30:28 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	error_print(void)
{
	printf("Invalid number");
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	t;

	t = 0;
	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = -1 * (str[i ++] - 44);
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i ++] - 48);
		if (t > result)
			return (-1 * (sign > 0));
		t = result;
	}
	if (str[i])
		error_print();
	return (result * sign);
}
