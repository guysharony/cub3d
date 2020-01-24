/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:53:23 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 12:57:04 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	spt_draw_y(t_env *e, t_draw_sprite draw)
{
	t_pos	drawy;

	drawy.x = -draw.size.y / 2 + e->resolution[1] / 2;
	if (drawy.x < 0)
		drawy.x = 0;
	drawy.y = draw.size.y / 2 + e->resolution[1] / 2;
	if (drawy.y >= e->resolution[1])
		drawy.y = e->resolution[1] - 1;
	return (drawy);
}

t_pos	spt_draw_x(t_env *e, t_draw_sprite draw)
{
	t_pos	drawx;

	drawx.x = -draw.size.x / 2 + draw.screenx;
	if (drawx.x < 0)
		drawx.x = 0;
	drawx.y = draw.size.x / 2 + draw.screenx;
	if (drawx.y >= e->resolution[0])
		drawx.y = e->resolution[0] - 1;
	return (drawx);
}
