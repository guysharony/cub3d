/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 11:21:18 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int		main(void)
{
	if ((mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((win = mlx_new_window(mlx, W, H, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	printf("\n___ Coloring map ___\n");
	ft_fill(win, W, H, 750);
	ft_text(win, W/2, H/2, 0, "Hello World");
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
