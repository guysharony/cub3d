/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlt_dst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:46:47 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:19:14 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_coo	dlt_dst(t_coo ray)
{
	t_coo	dlt;

	dlt.x = fabs(1 / ray.x);
	dlt.y = fabs(1 / ray.y);
	return (dlt);
}
