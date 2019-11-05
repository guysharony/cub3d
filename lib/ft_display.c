/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:26:53 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 12:16:23 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		ft_color(int r, int g, int b)
{
	return (b + (r << 16) + (g << 8));
}

void	ft_fill(void *win, int w, int h, int color)
{
	int x;
	int y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
			mlx_pixel_put(mlx, win, x, y, color);
	}
}

void	ft_text(void *win, int w, int h, int color, char *str)
{
	mlx_string_put(mlx, win, w, h, color, str);
}
