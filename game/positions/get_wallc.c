/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wallc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:39:25 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:12:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int		get_wc(t_env *e, t_draw_wall draw, int i, int dy)
{
	int		color;
	int		d;
	int		x;
	int		y;

	d = dy * 256 - (e->resolution[1]) * 128 + draw.lnh * 128;
	x = get_texture_posx(e, draw, i);
	y = ((d * e->textures[i].size.y) / draw.lnh) / 256;
	color = ((int *)e->textured[i])[((int *)e->texture[i])[0] * x + y];
	return (color);
}

int		get_wallc(t_env *e, t_draw_wall draw, int dy)
{
	int		color;

	if (draw.sde == 0)
	{
		if (draw.ray.x <= 0)
			color = get_wc(e, draw, 0, dy);
		else
			color = get_wc(e, draw, 1, dy);
	}
	else if (draw.sde == 1)
	{
		if (draw.ray.y > 0)
			color = get_wc(e, draw, 2, dy);
		else
			color = get_wc(e, draw, 3, dy);
	}
	if (draw.sde == 1)
		color = (color >> 1) & 8355711;
	return (color);
}
