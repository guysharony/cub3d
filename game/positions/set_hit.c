/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:36:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/25 16:03:14 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_draw_wall		set_hit(t_env *e, t_draw_wall draw)
{
	int		hit;
	int		mapc;

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
		mapc = e->game->map->map[draw.map.x][draw.map.y];
		if (!ft_includes(mapc, "02NSEW"))
			hit = 1;
	}
	return (draw);
}
