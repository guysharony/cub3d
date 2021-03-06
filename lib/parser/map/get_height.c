/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:34 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:42:45 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	getmap_height(t_game *game, char *map)
{
	int		file;
	int		width;
	char	*map_line;
	char	*line;

	file = open(map, O_RDONLY);
	if ((map_line = jumpto_map(file)) != NULL)
	{
		game->map->height++;
		free(map_line);
	}
	while (get_next_line(file, &line) > 0)
	{
		width = getmap_width(line);
		if (width > 1)
			game->map->height++;
		else
			break ;
		free(line);
	}
	if (getmap_width(line) > 1)
		game->map->height++;
	free(line);
}
