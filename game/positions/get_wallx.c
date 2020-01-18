#include "../../include/main.h"

double	get_wallx(t_env *e, t_draw draw)
{
	double	wallx;

	if (draw.sde == 0)
		wallx = e->player.pos.y + draw.wll * draw.ray.y;
	else
		wallx = e->player.pos.x + draw.wll * draw.ray.x;
	wallx -= floor(wallx);
	return (wallx);
}