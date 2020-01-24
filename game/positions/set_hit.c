/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:36:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:21:35 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_draw_wall		set_hit(t_env *e, t_draw_wall draw)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (draw.sld.x < draw.sld.y)
		{
			draw.sld.x += draw.dlt.x;
			draw.map.x += draw.stp.x;
			draw.sde = 0;
		}
		else
		{
			draw.sld.y += draw.dlt.y;
			draw.map.y += draw.stp.y;
			draw.sde = 1;
		}
		e->mapc = e->game->map->map[draw.map.x][draw.map.y];
		if (!ft_includes(e->mapc, "0,2,N,S,E,W"))
			hit = 1;
	}
	return (draw);
}
