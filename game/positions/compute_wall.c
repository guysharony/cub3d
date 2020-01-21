/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:14 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:46:42 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

double	compute_wall(t_env *e, t_draw_wall draw)
{
	double	wall;

	if (draw.sde == 0)
		wall = (draw.map.x - e->player.pos.x +
				(1 - draw.stp.x) / 2) / draw.ray.x;
	else
		wall = (draw.map.y - e->player.pos.y +
				(1 - draw.stp.y) / 2) / draw.ray.y;
	return (wall);
}
