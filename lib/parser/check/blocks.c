/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:35:41 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/25 17:52:28 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkblocks(t_game *game)
{
	int		a;
	int		b;
	int		e;

	a = 0;
	e = 0;
	while (game->map->map[a] != NULL)
	{
		b = 0;
		while (game->map->map[a][b])
		{
			if (!ft_includes(game->map->map[a][b], "012NSEW"))
				e += ft_error_line("Unvalid character", "MAP", a);
			b++;
		}
		a++;
	}
	if (e > 0)
		return (-1);
	return (1);
}
