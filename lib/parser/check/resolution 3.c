/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:31:45 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:49:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkresolution(char **resolution)
{
	int		a;
	int		e;

	a = 1;
	e = 0;
	while (resolution[a] != NULL)
	{
		if (ft_isnumber(resolution[a]))
		{
			if (ft_atoi(resolution[a]) < 0)
				e += ft_error("Lenth can't be negative!", resolution[a]);
		}
		else
			e += ft_error("Lenth must be a number!", resolution[a]);
		a++;
	}
	if (e > 0)
		return (-1);
	return (checkargnum(resolution, 3));
}
