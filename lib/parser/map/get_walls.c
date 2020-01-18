/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:06:42 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:27:04 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkchars(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int		checkwallsvup(t_game *game)
{
	int		a;
	int		b;
	int		e;

	a = 1;
	e = 0;
	while (game->map->map[a] != NULL)
	{
		if ((ft_strlen(game->map->map[a]) - 1) >
				ft_strlen(game->map->map[a - 1]))
		{
			b = ft_strlen(game->map->map[a - 1]) + 1;
			if (!checkchars(game->map->map[a], b, '1'))
				e += ft_error_line("[MAP]: Not closed at map line ", a);
		}
		a++;
	}
	if (e > 0)
		return (-1);
	return (1);
}

int		checkwallsvdown(t_game *game)
{
	int		a;
	int		b;
	int		e;

	a = game->map->height - 2;
	e = 0;
	while (a >= 0)
	{
		if ((ft_strlen(game->map->map[a]) - 1) >
				ft_strlen(game->map->map[a + 1]))
		{
			b = ft_strlen(game->map->map[a + 1]) + 1;
			if (!checkchars(game->map->map[a], b, '1'))
				e += ft_error_line("[MAP]: Not closed at map line ", a);
		}
		a--;
	}
	if (e > 0)
		return (-1);
	return (1);
}

int		checkwallsh(t_game *game)
{
	int		a;
	int		b;
	int		e;

	a = 0;
	e = 0;
	while (game->map->map[a] != NULL)
	{
		b = ft_strlen(game->map->map[a]);
		if (game->map->map[a][0] != '1' || game->map->map[a][b - 1] != '1')
			e += ft_error_line("[MAP]: Wall is missing at map line ", a);
		a++;
	}
	if (e > 0)
		return (-1);
	return (1);
}

int		checkwalls(t_game *game)
{
	if (checkwallsvup(game) == -1)
		return (-1);
	if (checkwallsvdown(game) == -1)
		return (-1);
	if (checkwallsh(game) == -1)
		return (-1);
	return (1);
}
