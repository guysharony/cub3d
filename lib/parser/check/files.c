/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:33:40 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/20 09:47:17 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkfiles(t_game *game)
{
	int		error;

	error = 0;
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
