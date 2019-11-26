/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:48:25 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/26 11:48:36 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	ContextToEnv(t_env *e)
{
	int				x;
	int				x1;

	x = 0;
	x1 = W * H;
	while (x < x1)
	{
		((unsigned int *)e->data)[x] = e->img_temp[x];
		x++;
	}
}
