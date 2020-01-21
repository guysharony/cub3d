/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_screenx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:42:22 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:45:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int		spt_screenx(t_env *e, t_draw_sprite draw)
{
	int		screenx;

	screenx = (int)((e->resolution[0] / 2) *
			(1 + draw.transform.x / draw.transform.y));
	return (screenx);
}
