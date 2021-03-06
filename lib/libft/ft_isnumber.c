/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:38:07 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 18:57:24 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isnumber(char *nb)
{
	int		a;

	a = 0;
	if (nb[a] == '-' || nb[a] == '+')
		a++;
	while (nb[a] != '\0')
	{
		if (nb[a] < '0' || nb[a] > '9')
			return (0);
		a++;
	}
	return (1);
}
