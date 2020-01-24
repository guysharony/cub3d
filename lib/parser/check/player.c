/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:34:28 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:49:49 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkplayerdef(t_game *game)
{
	int		a;
	int		b;
	int		count;

	a = 0;
	count = 0;
	while (game->map->map[a] != NULL)
	{
		b = 0;
		while (game->map->map[a][b])
		{
			if (ft_includes(game->map->map[a][b], "NSEW"))
				count++;
			b++;
		}
		a++;
	}
	if (count > 1)
	{
		ft_error("Player can't be at few places at the same time!", "MAP");
		return (-1);
	}
	return (1);
}

int		checkplayer(t_game *game)
{
	if (!ft_includes(game->player->direction, "NSEW"))
	{
		ft_error("Player position is not defined!", "MAP");
		return (-1);
	}
	return (1);
}
