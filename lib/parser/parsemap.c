/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:00:00 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:42:40 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	getmap(t_game *game, int file)
{
	int		a;
	int		width;
	char	*line;
	char	*map_line;

	a = 0;
	game->map->map = malloc(sizeof(char *) * game->map->height + 1);
	if ((map_line = jumpto_map(file)) != NULL)
		game->map->map[a++] = map_line;
	while (get_next_line(file, &line) > 0 &&
			a < game->map->height + 1 && game->map->height > 0)
	{
		width = getmap_width(line);
		if (width > 1)
		{
			map_line = getmap_line(line, width);
			game->map->map[a++] = map_line;
			free(line);
		}
		else
			break ;
	}
	free(line);
	game->map->map[a] = NULL;
}

void	getplayer(t_game *game)
{
	int		a;
	int		b;

	a = 0;
	while (game->map->map[a] != NULL)
	{
		b = 0;
		while (game->map->map[a][b])
		{
			if (ft_includes(game->map->map[a][b], "NSEW"))
			{
				game->player->direction = game->map->map[a][b];
				game->player->posx = b;
				game->player->posy = a;
				return ;
			}
			b++;
		}
		a++;
	}
}

int		parsemap(t_game *game, char *map)
{
	int		file;

	getmap_height(game, map);
	if (game->map->height > 0)
	{
		file = open(map, O_RDONLY);
		getmap(game, file);
		getplayer(game);
		return (check(game, file));
	}
	return (-1);
}
