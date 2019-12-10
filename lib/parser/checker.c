/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:43:09 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/10 09:25:53 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		contains(char *line, char c, int mod)
{
	int		a;

	a = 0;
	while (line[a])
	{
		if (mod == 0)
		{
			if (line[a] != c)
				return (1);
		}
		else if (mod == 1)
		{
			if (line[a] != c && (a == 0 || a == ft_strlen(line) - 1))
				return (1);
		}
		a++;
	}
	return (0);
}

int		check_map(char **map, int height)
{
	int		a;
	int		res;

	a = 0;
	while (map[a] != NULL)
	{
		if (a == 0 || a == height)
			res = contains(map[a], '1', 0);
		else
			res = contains(map[a], '1', 1);
		if (res != 0)
			return (res);
		a++;
	}
	return (0);
}
