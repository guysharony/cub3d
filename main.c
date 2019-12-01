/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/01 11:59:35 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

void	get_texture(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[0] = mlx_xpm_file_to_image(e->mlx, "./texture/wood.xpm", &iw, &ih);
	e->textureD[0] = mlx_get_data_addr(
		e->texture[0],
		&e->textureS[0].bpp,
		&e->textureS[0].sl,
		&e->textureS[0].endian
	);
	e->texture[1] = mlx_xpm_file_to_image(e->mlx, "./texture/redbrick.xpm", &iw, &ih);
	e->textureD[1] = mlx_get_data_addr(
		e->texture[1],
		&e->textureS[1].bpp,
		&e->textureS[1].sl,
		&e->textureS[1].endian
	);
	e->texture[2] = mlx_xpm_file_to_image(e->mlx, "./texture/mossy.xpm", &iw, &ih);
	e->textureD[2] = mlx_get_data_addr(
		e->texture[2],
		&e->textureS[2].bpp,
		&e->textureS[2].sl,
		&e->textureS[2].endian
	);
	e->texture[3] = mlx_xpm_file_to_image(e->mlx, "./texture/greystone.xpm", &iw, &ih);
	e->textureD[3] = mlx_get_data_addr(
		e->texture[3],
		&e->textureS[3].bpp,
		&e->textureS[3].sl,
		&e->textureS[3].endian
	);
}

void	ft_error(char *str)
{
	ft_putstr_fd(1, "Error\n");
	ft_putstr_fd(1, str);
	ft_putstr_fd(1, "\n");
}

void	game_loop(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	while (1)
	{
		mlx_hook(e->win, 17, 1L << 17, Exit, e);
		mlx_hook(e->win, 2, 1L << 0, KeyDown, e);
		mlx_hook(e->win, 3, 1L << 1, KeyUp, e);
		mlx_loop_hook(e->mlx, move, e);
		mlx_loop(e->mlx);
	}
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac > 1)
	{
		e = EnvInit(av);
		game_loop(e);
		free(e);
	}
	else
		ft_error("Please enter a valid argument.");
	return (EXIT_SUCCESS);
}
