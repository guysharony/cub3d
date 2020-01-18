/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlt_dst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:46:47 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:47:02 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	dlt_dst(t_env *e, t_coo ray)
{
	t_coo	dlt;

	dlt.x = abs(1 / ray.x);
	dlt.y = abs(1 / ray.y);
	return (dlt);
}
