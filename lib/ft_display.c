/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:26:53 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/07 08:14:06 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		ft_color(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r << 16) + (g << 8) + b);
}

void	ft_fill(t_env e, int w, int h, int color)
{
	int x;
	int y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
			mlx_pixel_put(e.mlx, e.win, x, y, color);
	}
}

void	ft_text(t_env e, int w, int h, int color, char *str)
{
	mlx_string_put(e.mlx, e.win, w, h, color, str);
}
