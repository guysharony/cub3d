/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:47:10 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:47:30 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	map_pos(t_env *e)
{
	t_pos	map;

	map.x = (int)e->player.pos.x;
	map.y = (int)e->player.pos.y;
	return (map);
}
