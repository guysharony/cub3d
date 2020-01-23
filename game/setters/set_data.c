/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:46:35 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/23 18:22:37 by guysharon        ###   ########.fr       */
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
		free(e->texture[0]);
		free(e->texture[1]);
		free(e->texture[2]);
		free(e->texture[3]);
		free(e->texture[4]);
		free(e->textured[0]);
		free(e->textured[1]);
		free(e->textured[2]);
		free(e->textured[3]);
		free(e->textured[4]);
		free(e->game);
		free(e);
		while (1);
		exit(0);
	}
	set_resolution(e);
	set_colors(e);
	set_player(e);
}
