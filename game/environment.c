/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:31:43 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/28 09:24:03 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_env	*EnvInit(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	CreateEnv(e);
	CreateContext(e);
	ContextToEnv(e);
	EnvToWindow(e, 0, 0);
	e->player.pos.x = 22.0;
	e->player.pos.y = 11.5;
	e->player.dir.x = -1.0;
	e->player.dir.y = 0.0;
	e->plane.x = 0;
	e->plane.y = 0.66;
	return (e);
}

void	CreateEnv(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W, H);
	e->data = mlx_get_data_addr(
		e->img,
		&e->setup.bpp,
		&e->setup.sl,
		&e->setup.endian
	);
}

void	CreateContext(t_env *e)
{
	int				x;
	int				y;
	t_vector		pov;
	int				color;
	unsigned int	*tmp;

	tmp = (unsigned int *)malloc(sizeof(unsigned int) * (W * H));
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			tmp[x + y * W] = ft_color(156, 227, 255);
			x++;
		}
		y++;
	}
	e->img_temp = tmp;
}

void	EnvToWindow(t_env *e, int x, int y)
{
	int		iw;
	int		ih;

	e->win = mlx_new_window(e->mlx, W, H, "3D World");
	mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
}
