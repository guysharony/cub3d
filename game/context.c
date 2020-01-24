/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:48:25 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 12:54:24 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	contexttoenv(t_env *e)
{
	int				x;
	int				x1;

	x = 0;
	x1 = e->resolution[0] * e->resolution[1];
	while (x < x1)
	{
		((unsigned int *)e->data)[x] = e->img_temp[x];
		x++;
	}
}
