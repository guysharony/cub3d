/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/08 07:59:38 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	create_img(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, W, H);
	e->data = mlx_get_data_addr(
		e->img,
		&e->setup.bpp,
		&e->setup.sl,
		&e->setup.endian
	);
}

t_vector	c_vector(int x, int y, int z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_ray		c_ray(t_vector i, t_vector j)
{
	t_ray	ray;

	ray.o = c_vector(i.x, i.y, i.z);
	ray.d = c_vector(j.x, j.y, j.z);
	return (ray);
}

void		ray_trace(t_env *e)
{
	int				x;
	int				y;
	t_ray			ray;
	t_vector		cam;
	unsigned int	*tmp;

	tmp = (unsigned int *)malloc(sizeof(unsigned int) * (W * H));
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			cam = c_vector(x + 100, y + 100, 1);
			ray = c_ray(cam, c_vector(0, 0, 1));
			tmp[x + y * W] = ft_color(156, 227, 255);
			x++;
		}
		y++;
	}
	e->img_temp = tmp;
}

void	samp(t_env *e)
{
	int				x;
	int				x1;

	x = 0;
	x1 = W * H;
	while (x < x1)
	{
		((unsigned int *)e->data)[x] = e->img_temp[x];
		x++;
	}
}

int		main(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	create_img(e);
	ray_trace(e);
	samp(e);
	if ((e->win = mlx_new_window(e->mlx, W, H, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	printf("\n___ Coloring map ___\n");
	mlx_key_hook(e->win, ft_key, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
	free(e);
	return (EXIT_SUCCESS);
}
