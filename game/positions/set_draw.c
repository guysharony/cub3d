/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:55:58 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/23 10:32:07 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int		get_drawc(t_env *e, t_draw_wall draw, int y)
{
	if (y < draw.drw.x)
		return (ft_color(e->ceiling[0], e->ceiling[1], e->ceiling[2]));
	else if (y >= draw.drw.y)
		return (ft_color(e->floor[0], e->floor[1], e->floor[2]));
	else
		return (get_wallc(e, draw, y));
}

void	get_spritec(t_env *e, t_draw_sprite draw, int ***buf, double **zbuf)
{
	int		color;
	int		d;
	t_pos	b;
	t_pos	t;

	b.x = draw.drawx.x;
	while (++b.x < draw.drawx.y)
	{
		if (draw.transform.y > 0 && b.x > 0 &&
				b.x < e->resolution[0] && draw.transform.y < (*zbuf)[b.x])
		{
			b.y = draw.drawy.x;
			while (++b.y < draw.drawy.y)
			{
				d = (b.y) * 256 - e->resolution[1] * 128 + draw.size.y * 128;
				t = spt_texture(e, draw, b.x, d);
				color = ((int *)e->textured[4])[TEXTUREW * t.y + t.x];
				if ((color & 0x00FFFFFF) != 0)
					(*buf)[b.x][b.y] = color;
			}
		}
	}
}

void	set_draw_wall(t_env *e, int x, int ***buf, double **zbuf)
{
	t_draw_wall		draw;
	int				y;

	y = 0;
	draw.cam = 2 * x / (double)(e->resolution[0]) - 1;
	draw.ray = ray_dir(e, draw.cam);
	draw.map = map_pos(e);
	draw.dlt = dlt_dst(e, draw.ray);
	draw.stp = get_stp(draw.ray);
	draw.sld = get_sld(e, draw.ray, draw.dlt, draw.map);
	draw = set_hit(e, draw);
	draw.wll = compute_wall(e, draw);
	draw.lnh = (int)((e->resolution[1]) / draw.wll);
	draw.drw.x = -draw.lnh / 2 + (e->resolution[1]) / 2;
	if (draw.drw.x < 0)
		draw.drw.x = 0;
	draw.drw.y = draw.lnh / 2 + (e->resolution[1]) / 2;
	if (draw.drw.y >= (e->resolution[1]))
		draw.drw.y = (e->resolution[1]);
	while (++y < e->resolution[1])
		(*buf)[x][y] = get_drawc(e, draw, y);
	(*zbuf)[x] = draw.wll;
}

void	set_draw_sprt(t_env *e, int x, int ***buf, double **zbuf)
{
	t_draw_sprite draw;

	draw.sprite = spt_pos(e, x);
	draw.invdet = spt_invdet(e, draw);
	draw.transform = spt_transform(e, draw);
	draw.screenx = spt_screenx(e, draw);
	draw.size = spt_size(e, draw);
	draw.drawx = spt_draw_x(e, draw);
	draw.drawy = spt_draw_y(e, draw);
	get_spritec(e, draw, buf, zbuf);
}
