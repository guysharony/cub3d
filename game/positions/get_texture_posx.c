/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_posx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:39:08 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 14:51:45 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int		get_texture_posx(t_env *e, t_draw_wall draw)
{
	int			texturex;
	double		wallx;

	wallx = get_wallx(e, draw);
	texturex = (int)(wallx * (double)(TEXTUREW));
	if (draw.sde == 0 && draw.ray.x > 0)
		texturex = TEXTUREW - texturex - 1;
	if (draw.sde == 1 && draw.ray.y < 0)
		texturex = TEXTUREW - texturex - 1;
	return (texturex);
}
