/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:46:18 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 12:49:40 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	ray_dir(t_env *e, double camerax)
{
	t_coo	ray;

	ray.x = e->player.dir.x + e->plane.x * camerax;
	ray.y = e->player.dir.y + e->plane.y * camerax;
	return (ray);
}
