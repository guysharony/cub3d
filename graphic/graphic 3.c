/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:32:05 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 14:29:55 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	drawlinebuffer(t_env *e, int x, int bff[])
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
	while (y++ < e->resolution[1] - 1)
		(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
}
