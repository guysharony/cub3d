/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:46:35 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 19:16:34 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_data(t_env *e, char *filename)
{
	e->game = (t_game *)malloc(sizeof(t_game));
	if (parse(e->game, filename))
	{
		set_resolution(e);
		set_colors(e);
		set_player(e);
	}
	else
		exitgame(e);
}
