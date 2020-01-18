/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sld_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:48:06 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:48:22 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	sld_int(t_env *e, t_pos map, t_coo dlt, t_coo ray)
{
	t_coo	sld;

	if (ray.x < 0)
		sld.x = (e->player.pos.x - map.x) * dlt.x;
	else
		sld.x = (map.x + 1.0 - e->player.pos.x) * dlt.x;
	if (ray.x < 0)
		sld.y = (e->player.pos.y - map.y) * dlt.y;
	else
		sld.y = (map.y + 1.0 - e->player.pos.y) * dlt.y;
	return (sld);
}
