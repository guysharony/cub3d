#include "../../include/main.h"

double	compute_sprite(t_env *e, t_draw draw)
{
	double	sprite;

	sprite = ((e->player.pos.x - draw.map.x) * (e->player.pos.x - draw.map.x) +
			(e->player.pos.y - draw.map.y) * (e->player.pos.y - draw.map.y));
	return (sprite);
}