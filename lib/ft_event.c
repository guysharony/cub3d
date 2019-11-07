/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:51:39 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/07 12:30:53 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_event(t_env e, void *p)
{
	mlx_key_hook(e.win, ft_key, p);
}

void	ft_left(t_env *e)
{
	e->setup.camera.x -= 1000;
	ray_trace(e);
	samp(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_right(t_env *e)
{
	e->setup.camera.x += 1000;
	ray_trace(e);
	samp(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		ft_key(int key, t_env *e)
{
	if (key == 123)
		ft_left(e);
	else if (key == 124)
		ft_right(e);
	else if (key == 125)
		printf("Down\n");
	else if (key == 126)
		printf("Up\n");
	else if (key == 53)
		exit(0);
	printf("Camera:\n[x: %d] - [y: %d]\n", e->setup.camera.x, e->setup.camera.y);
	return (0);
}
