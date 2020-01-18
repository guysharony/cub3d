/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:44:09 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:49:40 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkmap(t_game *game)
{
	int		error;

	error = 0;
	if (checkblocks(game) == -1)
		error++;
	if (checkwalls(game) == -1)
		error++;
	if (checkplayer(game) == -1)
		error++;
	if (checkplayerdef(game) == -1)
		error++;
	if (error > 0)
		return (-1);
	return (1);
}
