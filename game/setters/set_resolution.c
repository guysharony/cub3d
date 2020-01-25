/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:45:28 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 07:51:12 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_resolution(t_env *e)
{
	e->resolution[0] = ft_atoi(e->game->resolution[1]);
	if (e->resolution[0] > 2560)
		e->resolution[0] = 2560;
	e->resolution[1] = ft_atoi(e->game->resolution[2]);
	if (e->resolution[1] > 1440)
		e->resolution[1] = 1440;
	e->resolution[2] = e->resolution[0] * e->resolution[1];
}
