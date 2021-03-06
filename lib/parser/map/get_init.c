/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:02:57 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:16:02 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void			gameinit(t_game *game)
{
	game->resolution = NULL;
	game->wall->north = NULL;
	game->wall->south = NULL;
	game->wall->west = NULL;
	game->wall->east = NULL;
	game->wall->sprite = NULL;
	game->map->map = NULL;
	game->sprite->sprite = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
}
