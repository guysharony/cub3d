/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/10 09:19:42 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

void	get_texture(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[0] = mlx_xpm_file_to_image(e->mlx, e->game->T[0], &iw, &ih);
	e->textureD[0] = mlx_get_data_addr(
		e->texture[0],
		&e->textureS[0].bpp,
		&e->textureS[0].sl,
		&e->textureS[0].endian
	);
	e->texture[1] = mlx_xpm_file_to_image(e->mlx, e->game->T[1], &iw, &ih);
	e->textureD[1] = mlx_get_data_addr(
		e->texture[1],
		&e->textureS[1].bpp,
		&e->textureS[1].sl,
		&e->textureS[1].endian
	);
	e->texture[2] = mlx_xpm_file_to_image(e->mlx, e->game->T[2], &iw, &ih);
	e->textureD[2] = mlx_get_data_addr(
		e->texture[2],
		&e->textureS[2].bpp,
		&e->textureS[2].sl,
		&e->textureS[2].endian
	);
	e->texture[3] = mlx_xpm_file_to_image(e->mlx, e->game->T[3], &iw, &ih);
	e->textureD[3] = mlx_get_data_addr(
		e->texture[3],
		&e->textureS[3].bpp,
		&e->textureS[3].sl,
		&e->textureS[3].endian
	);
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
	int		a;

	if (ac > 1)
	{
		a = 0;
		e = EnvInit(av);
		if (e->game->status != 0)
		{
			ft_error("The map must be surounded by walls!");
			return (EXIT_SUCCESS);
		}
		game_loop(e);
		free(e);
	}
	else
		ft_error("Please enter a valid argument.");
	return (EXIT_SUCCESS);
}
