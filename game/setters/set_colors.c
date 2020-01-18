/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:44:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:42:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_colors(t_env *e)
{
	char	**floor;
	char	**ceiling;

	floor = parsecolor(e->game->floor[1]);
	e->floor[0] = ft_atoi(floor[0]);
	e->floor[1] = ft_atoi(floor[1]);
	e->floor[2] = ft_atoi(floor[2]);
	clean(floor);
	ceiling = parsecolor(e->game->ceiling[1]);
	e->ceiling[0] = ft_atoi(ceiling[0]);
	e->ceiling[1] = ft_atoi(ceiling[1]);
	e->ceiling[2] = ft_atoi(ceiling[2]);
	clean(ceiling);
}
