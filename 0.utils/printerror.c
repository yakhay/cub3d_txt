/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhn <dhn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:10:04 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 11:50:28 by dhn              ###   ########.fr       */
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