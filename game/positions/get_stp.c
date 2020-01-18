#include "../../include/main.h"

t_pos	get_stp(t_coo ray)
{
	t_pos	stp;

	if (ray.x < 0)
		stp.x = -1;
	else
		stp.x = 1;
	if (ray.y < 0)
		stp.y = -1;
	else
		stp.y = 1;
	return (stp);
}