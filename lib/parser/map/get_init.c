/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:02:57 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 13:03:16 by gsharony         ###   ########.fr       */
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
	game->sprite = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
}
