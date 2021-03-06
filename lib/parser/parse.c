/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:30:27 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:12:58 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_clean(t_game *game)
{
	clean(game->resolution);
	clean(game->wall->north);
	clean(game->wall->south);
	clean(game->wall->east);
	clean(game->wall->west);
	clean(game->wall->sprite);
	free(game->wall);
	clean(game->ceiling);
	clean(game->floor);
	free(game->player);
	if (game->sprite->sprite != NULL)
		free(game->sprite->sprite);
	free(game->sprite);
	if (game->map->map != NULL)
		clean(game->map->map);
	free(game->map);
}

int		parse(t_game *game, char *filename)
{
	int		error;

	game->wall = (t_texture *)malloc(sizeof(t_texture));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	error = parsecommands(game, filename);
	if (error == -1)
	{
		ft_clean(game);
		return (error);
	}
	error = parsemap(game, filename);
	if (error == -1)
	{
		ft_clean(game);
		return (error);
	}
	return (1);
}
