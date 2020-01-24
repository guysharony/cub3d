/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:48:36 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:47:50 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	spt_transform(t_env *e, t_draw_sprite draw)
{
	t_coo	transform;

	transform.x = draw.invdet * (e->player.dir.y * draw.sprite.x -
			e->player.dir.x * draw.sprite.y);
	transform.y = draw.invdet * (-e->plane.y * draw.sprite.x +
			e->plane.x * draw.sprite.y);
	return (transform);
}
