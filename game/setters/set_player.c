/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:45:51 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/25 16:07:04 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_player_south(t_env *e)
{
	e->player.dir.x = 1.0;
	e->player.dir.y = 0.0;
	e->plane.x = 0.0;
	e->plane.y = -0.65;
}

void	set_player_north(t_env *e)
{
	e->player.dir.x = -1.0;
	e->player.dir.y = 0.0;
	e->plane.x = 0;
	e->plane.y = 0.65;
}

void	set_player_east(t_env *e)
{
	e->player.dir.x = 0.0;
	e->player.dir.y = 1.0;
	e->plane.x = 0.65;
	e->plane.y = 0.0;
}

void	set_player_west(t_env *e)
{
	e->player.dir.x = 0.0;
	e->player.dir.y = -1.0;
	e->plane.x = -0.65;
	e->plane.y = 0.0;
}

void	set_player(t_env *e)
{
	e->player.pos.x = e->game->player->posx + 0.5;
	e->player.pos.y = e->game->player->posy + 0.5;
	if (e->game->player->direction == 'N')
		set_player_north(e);
	else if (e->game->player->direction == 'S')
		set_player_south(e);
	else if (e->game->player->direction == 'E')
		set_player_east(e);
	else if (e->game->player->direction == 'W')
		set_player_west(e);
}
