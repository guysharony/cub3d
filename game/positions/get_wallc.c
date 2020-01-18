#include "../../include/main.h"

int		get_wallc(t_env *e, t_draw draw, int dy)
{
	int		color;
	int		x;
	int		y;
	int		d;

	d = dy * 256 - (e->resolution[1]) * 128 + draw.lnh * 128;
	x = get_texture_posx(e, draw);
	y = ((d * textureh) / draw.lnh) / 256;
	if (draw.sde == 0)
	{
		if (draw.ray.x > 0)
			color = ((int *)e->textureD[0])[((int *)e->texture[0])[0] * x + y];
		else
			color = ((int *)e->textureD[1])[((int *)e->texture[1])[0] * x + y];
	}
	else if (draw.sde == 1)
	{
		if (draw.ray.y > 0)
			color = ((int *)e->textureD[2])[((int *)e->texture[2])[0] * x + y];
		else
			color = ((int *)e->textureD[3])[((int *)e->texture[3])[0] * x + y];
	}
	if (draw.sde == 1)
		color = (color >> 1) & 8355711;
	return (color);
}