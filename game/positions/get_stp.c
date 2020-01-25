/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:46:22 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:46:24 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_pos	get_stp(t_coo ray)
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
