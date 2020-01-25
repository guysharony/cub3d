/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:32:31 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:49:16 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkcolor(char **color)
{
	int		a;
	int		e;
	char	**rgb;

	a = 0;
	e = 0;
	rgb = parsecolor(color[1]);
	while (rgb[a] != NULL)
	{
		if (ft_isnumber(rgb[a]))
		{
			if (ft_atoi(rgb[a]) < 0 || ft_atoi(rgb[a]) > 255)
				e += ft_error("Invalid pixel color!", rgb[a]);
		}
		else
			e += ft_error("Color must contain only numbers!", rgb[a]);
		if (a > 3)
			e += ft_error("Only three colors are expected!", rgb[a]);
		free(rgb[a]);
		a++;
	}
	free(rgb);
	if (e > 0)
		return (-1);
	return (checkargnum(color, 2));
}
