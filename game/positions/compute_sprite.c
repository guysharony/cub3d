/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:38:35 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 12:38:37 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

double	compute_sprite(t_env *e, t_draw_wall draw)
{
	double	sprite;

	sprite = ((e->player.pos.x - draw.map.x) * (e->player.pos.x - draw.map.x) +
			(e->player.pos.y - draw.map.y) * (e->player.pos.y - draw.map.y));
	return (sprite);
}
