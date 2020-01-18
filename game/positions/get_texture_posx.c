#include "../../include/main.h"

int		get_texture_posx(t_env *e, t_draw draw)
{
	int			texturex;
	double		wallx;

	wallx = get_wallx(e, draw);
	texturex = (int)(wallx * (double)(texturew));
	if (draw.sde == 0 && draw.ray.x > 0)
		texturex = texturew - texturex - 1;
	if (draw.sde == 1 && draw.ray.y < 0)
		texturex = texturew - texturex - 1;
	return (texturex);
}