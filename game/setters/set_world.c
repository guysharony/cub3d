/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:47:37 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 12:07:20 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	set_world(t_env *e)
{
	e->mlx = mlx_init();
	createenv(e);
	createcontext(e);
	contexttoenv(e);
	envtowindow(e, 0, 0);
	get_texture(e);
	draw(e);
}
