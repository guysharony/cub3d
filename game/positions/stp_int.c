/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stp_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:47:38 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 14:47:56 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	stp_int(t_coo ray)
{
	t_pos	stp;

	if (ray.x < 0)
		stp.x = -1;
	else
		stp.x = 1;
	if (ray.y < 0)
		stp.y = -1;
	else
		stp.y = 1;
	return (stp);
}
