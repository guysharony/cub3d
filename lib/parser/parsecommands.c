/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:54 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 13:02:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int		isdefined(t_game *game, char **data)
{
	int		res;

	res = ispresent(data[0], "R,NO,SO,WE,EA,S,F,C");
	if (res == 0)
		return (game->resolution != NULL);
	if (res == 1)
		return (game->wall->north != NULL);
	if (res == 2)
		return (game->wall->south != NULL);
	if (res == 3)
		return (game->wall->west != NULL);
	if (res == 4)
		return (game->wall->east != NULL);
	if (res == 5)
		return (game->sprite != NULL);
	if (res == 6)
		return (game->floor != NULL);
	if (res == 7)
		return (game->ceiling != NULL);
	return (-1);
}

static int		iscommand(t_game **game, char **data)
{
	int		res;

	res = ispresent(data[0], "R,NO,SO,WE,EA,S,F,C");
	if (res >= 0)
	{
		if (isdefined(*game, data) == 1)
			return (ft_error_redefined(res));
		if (res == 0)
			(*game)->resolution = data;
		else if (res == 1)
			(*game)->wall->north = data;
		else if (res == 2)
			(*game)->wall->south = data;
		else if (res == 3)
			(*game)->wall->west = data;
		else if (res == 4)
			(*game)->wall->east = data;
		else if (res == 5)
			(*game)->sprite = data;
		else if (res == 6)
			(*game)->floor = data;
		else if (res == 7)
			(*game)->ceiling = data;
	}
	return (res);
}

static int		ismissing(t_game *game)
{
	int		a;

	a = 0;
	if (game->resolution == NULL)
		a += ft_error("Not defined before map!", "R");
	if (game->wall->north == NULL)
		a += ft_error("Not defined before map!", "NO");
	if (game->wall->south == NULL)
		a += ft_error("Not defined before map!", "SO");
	if (game->wall->east == NULL)
		a += ft_error("Not defined before map!", "EA");
	if (game->wall->west == NULL)
		a += ft_error("Not defined before map!", "WE");
	if (game->sprite == NULL)
		a += ft_error("Not defined before map!", "S");
	if (game->floor == NULL)
		a += ft_error("Not defined before map!", "F");
	if (game->ceiling == NULL)
		a += ft_error("Not defined before map!", "C");
	return (a);
}

static int		iscomplete(t_game *game)
{
	if (game->resolution == NULL)
		return (0);
	if (game->wall->north == NULL)
		return (0);
	if (game->wall->south == NULL)
		return (0);
	if (game->wall->east == NULL)
		return (0);
	if (game->wall->west == NULL)
		return (0);
	if (game->sprite == NULL)
		return (0);
	if (game->floor == NULL)
		return (0);
	if (game->ceiling == NULL)
		return (0);
	return (1);
}

int				parsecommands(t_game *game, char *map)
{
	int		file;
	int		res;
	int		error;
	char	*line;
	char	**data;

	error = 0;
	gameinit(game);
	file = open(map, O_RDONLY);
	while ((res = get_next_line(file, &line)) > 0 && iscomplete(game) == 0)
	{
		data = ft_split(line, ' ');
		if (data[0] != NULL)
		{
			if (iscommand(&game, data) == -1)
				error += ft_error("Unknown command!", data[0]);
		}
		else
			free(data);
		free(line);
	}
	free(line);
	if (ismissing(game) > 0 || error > 0)
		return (-1);
	return (1);
}
