/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spt_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:36:33 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:48:50 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	spt_texture(t_env *e, t_draw_sprite draw, int i, int d)
{
	t_pos texture;

	texture.x = (int)(256 * (i - (-draw.size.x / 2 + draw.screenx)) *
			texturew / draw.size.x) / 256;
	texture.y = ((d * textureh) / draw.size.y) / 256;
	return (texture);
}
