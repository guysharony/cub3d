/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispresent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:53:23 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:53:26 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ispresent(char *data, char *commands)
{
	int		a;
	int		b;
	char	**coms;

	a = 0;
	coms = ft_split(commands, ',');
	while (coms[a] != NULL)
	{
		b = 0;
		while (data[b] && coms[a][b] && data[b] == coms[a][b])
			b++;
		if (data[b] != coms[a][b])
			a++;
		else
		{
			clean(coms);
			return (a);
		}
	}
	clean(coms);
	return (-1);
}
