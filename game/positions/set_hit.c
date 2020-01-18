#include "../../include/main.h"

t_draw	set_hit(t_env *e, t_draw draw)
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
		if (!ft_includes(mapc, "0,N,S,E,W"))
			hit = 1;
	}
	return (draw);
}