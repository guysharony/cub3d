/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:44:09 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/25 17:53:20 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkwallnorth(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map->map[y][x])
	{
		if (game->map->map[y][x] != '1')
		{
			ft_error_line("Not surrounded by walls", "MAP", y);
			return (-1);
		}
		x++;
	}
	return (1);
}

int		checkwallsouth(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = game->map->height - 1;
	while (game->map->map[y][x])
	{
		if (game->map->map[y][x] != '1')
		{
			ft_error_line("Not surrounded by walls", "MAP", y);
			return (-1);
		}
		x++;
	}
	return (1);
}

int		checkmap(t_game *game)
{
	int		error;

	error = 0;
	if (checkblocks(game) == -1)
		error++;
	if (checkwallsouth(game) == -1)
		error++;
	if (checkwallnorth(game) == -1)
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
