/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 18:44:42 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	draw(t_env *e)
{
	int			x;
	int			y;
	int			buf[e->resolution[1]];
	t_draw		draw;

	x = 0;
	createenv(e);
	free(e->img_temp);
	createcontext(e);
	contexttoenv(e);
	while (x < e->resolution[0])
	{
		draw = set_draw(e, x);
		for (y = draw.drw.x; y < draw.drw.y; y++)
		{
			draw.clr = get_wallc(e, draw, y);
			buf[y - draw.drw.x] = draw.clr;
		}
		drawlinebuffer(e, x, draw.drw.x, x, draw.drw.y, buf);
		x++;
	}
}
