/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/26 11:46:33 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

unsigned long	get_texture(int nb, int x, int y)
{
	int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
	int ycolor = y * 256 / texHeight;
	int xycolor = y * 128 / texHeight + x * 128 / texWidth;
	if (nb == 0)
		return (65536 * 254 * (x != y && x != texWidth - y));
	else if (nb == 1)
		return (xycolor + 256 * xycolor + 65536 * xycolor);
	else if (nb == 2)
		return (256 * xycolor + 65536 * xycolor);
	else if (nb == 3)
		return (xorcolor + 256 * xorcolor + 65536 * xorcolor);
	else if (nb == 4)
		return (256 * xorcolor);
	else if (nb == 5)
		return (65536 * 192 * (x % 16 && y % 16));
	else if (nb == 6)
		return (65536 * ycolor);
	else if (nb == 7)
		return (128 + 256 * 128 + 65536 * 128);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		x;

	if (ac > 1)
	{
		e = EnvInit();
		e->map = get_file(av[1]);
		draw(e);
		ContextToEnv(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		while (1)
		{
			mlx_hook(e->win, 2, 1L << 0, KeyDown, e);
			mlx_hook(e->win, 3, 1L << 1, KeyUp, e);
			mlx_loop(e->mlx);
		}
		free(e);
	}
	else
		write(1, "Error\nPlease enter map file!\n", 30);
	return (EXIT_SUCCESS);
}
