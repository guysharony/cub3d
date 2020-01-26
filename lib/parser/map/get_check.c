/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:27 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/23 12:36:43 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		check(t_game *game, int file)
{
	int		error;

	error = 0;
	if (checkmap(game) == -1)
		error++;
	if (checkfiles(game) == -1)
		error++;
	if (checkcolor(game->floor) == -1)
		error++;
	if (checkcolor(game->ceiling) == -1)
		error++;
	if (checkresolution(game->resolution) == -1)
		error++;
	if (checkend(file) == -1)
		error++;
	if (error > 0)
		return (-1);
	return (1);
}
