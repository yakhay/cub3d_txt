/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:10:04 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/14 06:05:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	printerror(const char *msg, const char *sp)
{
	printf("Error:\n %s", msg);
	if (sp && *sp)
		printf(": %s", sp);
	printf("\n");
	exit(1);
}
