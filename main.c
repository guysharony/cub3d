/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 08:56:48 by gsharony         ###   ########.fr       */
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

int		check_arguments(int ac, char **av)
{
	int e;

	e = 0;
	if (ac > 1 && ac < 4)
	{
		if (ac == 3 && ft_strcmp(av[2], "-save") != 0)
			e++;
		if (ft_isftype(av[1], "cub") == -1)
			e++;
	}
	else if (ac < 2)
		e += ft_error("Map file needed.", NULL);
	else if (ac > 3)
		e += ft_error("Too many arguments.", NULL);
	if (e > 0)
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		save;

	save = 0;
	if (check_arguments(ac, av) == -1)
		exit(0);
	if (ac == 3)
		save = 1;
	e = envinit(av, save);
	game_loop(e);
	return (EXIT_SUCCESS);
}
