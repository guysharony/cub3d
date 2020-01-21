/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:46:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:46:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	get_sld(t_env *e, t_coo ray, t_coo dlt, t_pos map)
{
	t_coo	sld;

	if (ray.x < 0)
		sld.x = (e->player.pos.x - map.x) * dlt.x;
	else
		sld.x = (map.x + 1.0 - e->player.pos.x) * dlt.x;
	if (ray.y < 0)
		sld.y = (e->player.pos.y - map.y) * dlt.y;
	else
		sld.y = (map.y + 1.0 - e->player.pos.y) * dlt.y;
	return (sld);
}
