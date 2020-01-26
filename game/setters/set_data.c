/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:46:35 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:46:55 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_data(t_env *e, char *filename)
{
	int		status;

	e->game = (t_game *)malloc(sizeof(t_game));
	status = parse(e->game, filename);
	if (status == -1)
	{
		free(e->game);
		free(e);
		exit(0);
	}
	set_resolution(e);
	set_colors(e);
	set_player(e);
}
