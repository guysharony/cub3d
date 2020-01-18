#include "../../include/main.h"

t_draw	set_draw(t_env *e, int x)
{
	t_draw draw;

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
		draw.drw.y = (e->resolution[1]) - 1;
	return (draw);
}