/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_backward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:34:04 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/19 14:30:16 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	move_backward(t_env *e, double movespeed)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = (int)(e->player.pos.x + e->player.dir.x * movespeed);
	x2 = (int)(e->player.pos.x);
	y1 = (int)(e->player.pos.y + e->player.dir.y * movespeed);
	y2 = (int)(e->player.pos.y);
	if (ft_includes(e->game->map->map[x1][y2], "0,2,N,S,E,W"))
		e->player.pos.x -= e->player.dir.x * movespeed;
	if (ft_includes(e->game->map->map[x2][y1], "0,2,N,S,E,W"))
		e->player.pos.y -= e->player.dir.y * movespeed;
}
