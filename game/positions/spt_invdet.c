/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_invdet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:40:04 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:21:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

double		spt_invdet(t_env *e)
{
	double	invdet;

	invdet = 1.0 / (e->plane.x * e->player.dir.y -
			e->player.dir.x * e->plane.y);
	return (invdet);
}
