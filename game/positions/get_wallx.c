/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wallx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:49 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 12:38:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

double	get_wallx(t_env *e, t_draw_wall draw)
{
	double	wallx;

	if (draw.sde == 0)
		wallx = e->player.pos.y + draw.wll * draw.ray.y;
	else
		wallx = e->player.pos.x + draw.wll * draw.ray.x;
	wallx -= floor(wallx);
	return (wallx);
}
