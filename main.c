/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/19 09:05:26 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

void	get_texture(t_env *e)
{
	get_texture_north(e);
	get_texture_south(e);
	get_texture_east(e);
	get_texture_west(e);
	get_texture_sprite(e);
}

void	game_loop(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	while (1)
	{
		mlx_hook(e->win, 17, 1L << 17, exitgame, e);
		mlx_hook(e->win, 2, 1L << 0, keydown, e);
		mlx_hook(e->win, 3, 1L << 1, keyup, e);
		mlx_loop_hook(e->mlx, move, e);
		mlx_loop(e->mlx);
	}
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac > 1)
	{
		e = envinit(av);
		game_loop(e);
		ft_clean(e->game);
	}
	else
		ft_error("Please enter a valid argument.", NULL);
	return (EXIT_SUCCESS);
}
