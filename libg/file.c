/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:33:43 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/25 09:47:25 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libg.h"

char	**get_file(char *name)
{
	int		i;
	int		fle;
	int		ret;
	char	*ln;
	char	**map;

	i = 0;
	fle = open(name, O_RDONLY);
	map = malloc(sizeof(map) * 24);
	while ((ret = get_next_line(fle, &ln)) != 0)
	{
		map[i] = malloc(sizeof(char *) * 25);
		ft_strcpy(map[i], ln);
		free(ln);
		i++;
	}
	return (map);
}
