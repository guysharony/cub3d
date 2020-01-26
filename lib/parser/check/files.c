/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:33:40 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 11:11:25 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		ft_checkargs(t_texture *wall)
{
	int		error;

	error = 0;
	if (checkargnum(wall->north, 1) == -1)
		error++;
	if (checkargnum(wall->south, 1) == -1)
		error++;
	if (checkargnum(wall->east, 1) == -1)
		error++;
	if (checkargnum(wall->west, 1) == -1)
		error++;
	if (checkargnum(wall->sprite, 1) == -1)
		error++;
	if (error > 0)
		return (-1);
	return (1);
}

int		checkfiles(t_game *game)
{
	int		error;

	error = 0;
	if (ft_checkargs(game->wall) == -1)
		error++;
	if (ft_isftype(game->wall->north[1], "xpm") == -1)
		error++;
	if (ft_isftype(game->wall->south[1], "xpm") == -1)
		error++;
	if (ft_isftype(game->wall->east[1], "xpm") == -1)
		error++;
	if (ft_isftype(game->wall->west[1], "xpm") == -1)
		error++;
	if (ft_isftype(game->wall->sprite[1], "xpm") == -1)
		error++;
	if (error > 0)
		return (-1);
	return (1);
}
