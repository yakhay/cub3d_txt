/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:05:16 by yodahani          #+#    #+#             */
/*   Updated: 2022/10/27 21:06:45 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (str[i])
		i ++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char ) c)
			return ((char *)str + i);
		i --;
	}
	return (0);
}
