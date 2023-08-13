/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:21:05 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/21 18:33:22 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reitoa(char *s, long n)
{
	if (n / 10 > 0)
	{
		s = ft_reitoa(s, n / 10);
		s ++;
		*s = n % 10 + '0';
		return (s);
	}
	else
	{
		*s = n + 48;
		return (s);
	}
}

static int	ft_countnum(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count ++;
	}
	while ((n / 10) > 0)
	{
		n /= 10;
		count ++;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	num = n;
	count = ft_countnum(num);
	str = (char *) malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		*str = '-';
		ft_reitoa(str + 1, num);
	}
	else
		ft_reitoa(str, num);
	str[count] = '\0';
	return (str);
}
