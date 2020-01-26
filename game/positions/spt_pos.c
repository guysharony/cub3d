/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:46:26 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 12:48:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	spt_pos(t_env *e, int x)
{
	t_coo	pos;

	pos.x = (e->game->sprite->sprite[x].x - e->player.pos.x) + 0.5;
	pos.y = (e->game->sprite->sprite[x].y - e->player.pos.y) + 0.5;
	return (pos);
}
