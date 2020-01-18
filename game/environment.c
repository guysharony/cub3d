/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:31:43 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 20:05:16 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_env	*envinit(char **av)
{
	t_env		*e;

	e = (t_env *)malloc(sizeof(t_env));
	set_data(e, av[1]);
	set_world(e);
	return (e);
}

void	createenv(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->resolution[0], e->resolution[1]);
	e->data = mlx_get_data_addr(
			e->img,
			&e->setup.bpp,
			&e->setup.sl,
			&e->setup.endian);
}

void	createcontext(t_env *e)
{
	int				x;
	int				y;
	int				color;
	unsigned int	*tmp;

	tmp = (unsigned int *)malloc(sizeof(unsigned int) * e->resolution[2]);
	y = 0;
	while (y < (e->resolution[1]))
	{
		x = 0;
		while (x < (e->resolution[0]))
		{
			if (y < (e->resolution[1] / 2))
				color = ft_color(e->ceiling[0], e->ceiling[1], e->ceiling[2]);
			else
				color = ft_color(e->floor[0], e->floor[1], e->floor[2]);
			tmp[x + y * (e->resolution[0])] = color;
			x++;
		}
		y++;
	}
	e->img_temp = tmp;
}

void	envtowindow(t_env *e, int x, int y)
{
	int		iw;
	int		ih;

	iw = e->resolution[0];
	ih = e->resolution[1];
	e->win = mlx_new_window(e->mlx, iw, ih, "3D World");
	mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
}
