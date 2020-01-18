#include "../../include/main.h"

double	compute_wall(t_env *e, t_draw draw)
{
	double	wall;

	if (draw.sde == 0)
		wall = (draw.map.x - e->player.pos.x + (1 - draw.stp.x) / 2) / draw.ray.x;
	else
		wall = (draw.map.y - e->player.pos.y + (1 - draw.stp.y) / 2) / draw.ray.y;
	return (wall);
}