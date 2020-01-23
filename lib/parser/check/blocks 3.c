/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:35:41 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:49:05 by gsharony         ###   ########.fr       */
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
				e += ft_error_line("[MAP]: Unvalid character at map line ", a);
			b++;
		}
		a++;
	}
	if (e > 0)
		return (-1);
	return (1);
}
