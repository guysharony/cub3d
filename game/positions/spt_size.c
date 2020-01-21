/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:14 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:08:38 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	spt_size(t_env *e, t_draw_sprite draw)
{
	t_pos	size;

	size.y = abs((int)(e->resolution[1] / (draw.transform.y)));
	size.x = abs((int)(e->resolution[1] / (draw.transform.y)));
	return (size);
}
