/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:35:48 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:40:44 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	rotate_left(t_env *e, double rotspeed)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->player.dir.x;
	oldplanex = e->plane.x;
	e->player.dir.x = e->player.dir.x * cos(-rotspeed) -
		e->player.dir.y * sin(-rotspeed);
	e->player.dir.y = olddirx * sin(-rotspeed) +
		e->player.dir.y * cos(-rotspeed);
	e->plane.x = e->plane.x * cos(-rotspeed) - e->plane.y * sin(-rotspeed);
	e->plane.y = oldplanex * sin(-rotspeed) + e->plane.y * cos(-rotspeed);
}
