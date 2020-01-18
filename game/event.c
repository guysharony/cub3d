/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:25:45 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 19:01:20 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		move(t_env *e)
{
	double		movespeed;
	double		rotspeed;

	movespeed = 0.06;
	rotspeed = 0.06;
	if (e->keys.t_13 == 1)
		move_forward(e, movespeed);
	if (e->keys.t_1 == 1)
		move_backward(e, movespeed);
	if (e->keys.t_0 == 1)
		move_left(e, movespeed);
	if (e->keys.t_2 == 1)
		move_right(e, movespeed);
	if (e->keys.t_124 == 1)
		rotate_left(e, rotspeed);
	if (e->keys.t_123 == 1)
		rotate_right(e, rotspeed);
	printf("[dir_x: %f - dir_y: %f] - [plane_x: %f - plane_y: %f]\n", e->player.dir.x, e->player.dir.y, e->plane.x, e->plane.y);
	draw(e);
	contexttoenv(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		keydown(int key, t_env *e)
{
	if (key == 13)
		e->keys.t_13 = 1;
	else if (key == 1)
		e->keys.t_1 = 1;
	else if (key == 2)
		e->keys.t_2 = 1;
	else if (key == 0)
		e->keys.t_0 = 1;
	else if (key == 123)
		e->keys.t_123 = 1;
	else if (key == 124)
		e->keys.t_124 = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int		keyup(int key, t_env *e)
{
	if (key == 13)
		e->keys.t_13 = 0;
	else if (key == 1)
		e->keys.t_1 = 0;
	else if (key == 2)
		e->keys.t_2 = 0;
	else if (key == 0)
		e->keys.t_0 = 0;
	else if (key == 123)
		e->keys.t_123 = 0;
	else if (key == 124)
		e->keys.t_124 = 0;
	return (0);
}

int		exitgame(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}
