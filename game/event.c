/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:25:45 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/26 11:48:59 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		KeyDown(int key, t_env *e)
{
	double moveSpeed = 0.08 * 3.0;
	double rotSpeed = 0.08 * 1.0;
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
	if (e->keys.t_13 == 1)
	{
		if(e->map[(int)(e->player.pos.x + e->player.dir.x * moveSpeed)][(int)(e->player.pos.y)] == '0')
			e->player.pos.x += e->player.dir.x * moveSpeed;
		if(e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y + e->player.dir.y * moveSpeed)] == '0')
			e->player.pos.y += e->player.dir.y * moveSpeed;
	}
	if (e->keys.t_1 == 1)
	{
		if(e->map[(int)(e->player.pos.x - e->player.dir.x * moveSpeed)][(int)(e->player.pos.y)] == '0')
			e->player.pos.x -= e->player.dir.x * moveSpeed;
		if(e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y - e->player.dir.y * moveSpeed)] == '0')
			e->player.pos.y -= e->player.dir.y * moveSpeed;
	}
	if (e->keys.t_124 == 1)
	{
		double oldDirX = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(-rotSpeed) - e->player.dir.y * sin(-rotSpeed);
		e->player.dir.y = oldDirX * sin(-rotSpeed) + e->player.dir.y * cos(-rotSpeed);
		double oldPlaneX = e->plane.x;
		e->plane.x = e->plane.x * cos(-rotSpeed) - e->plane.y * sin(-rotSpeed);
		e->plane.y = oldPlaneX * sin(-rotSpeed) + e->plane.y * cos(-rotSpeed);
	}
	if (e->keys.t_123 == 1)
	{
		double oldDirX = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(rotSpeed) - e->player.dir.y * sin(rotSpeed);
		e->player.dir.y = oldDirX * sin(rotSpeed) + e->player.dir.y * cos(rotSpeed);
		double oldPlaneX = e->plane.x;
		e->plane.x = e->plane.x * cos(rotSpeed) - e->plane.y * sin(rotSpeed);
		e->plane.y = oldPlaneX * sin(rotSpeed) + e->plane.y * cos(rotSpeed);
	}
	draw(e);
	ContextToEnv(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		KeyUp(int key, t_env *e)
{
	double moveSpeed = 0.08 * 3.0;
	double rotSpeed = 0.08 * 1.0;
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
	if (e->keys.t_13 == 1)
	{
		if(e->map[(int)(e->player.pos.x + e->player.dir.x * moveSpeed)][(int)(e->player.pos.y)] == '0')
			e->player.pos.x += e->player.dir.x * moveSpeed;
		if(e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y + e->player.dir.y * moveSpeed)] == '0')
			e->player.pos.y += e->player.dir.y * moveSpeed;
	}
	if (e->keys.t_1 == 1)
	{
		if(e->map[(int)(e->player.pos.x - e->player.dir.x * moveSpeed)][(int)(e->player.pos.y)] == '0')
			e->player.pos.x -= e->player.dir.x * moveSpeed;
		if(e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y - e->player.dir.y * moveSpeed)] == '0')
			e->player.pos.y -= e->player.dir.y * moveSpeed;
	}
	if (e->keys.t_124 == 1)
	{
		double oldDirX = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(-rotSpeed) - e->player.dir.y * sin(-rotSpeed);
		e->player.dir.y = oldDirX * sin(-rotSpeed) + e->player.dir.y * cos(-rotSpeed);
		double oldPlaneX = e->plane.x;
		e->plane.x = e->plane.x * cos(-rotSpeed) - e->plane.y * sin(-rotSpeed);
		e->plane.y = oldPlaneX * sin(-rotSpeed) + e->plane.y * cos(-rotSpeed);
	}
	if (e->keys.t_123 == 1)
	{
		double oldDirX = e->player.dir.x;
		e->player.dir.x = e->player.dir.x * cos(rotSpeed) - e->player.dir.y * sin(rotSpeed);
		e->player.dir.y = oldDirX * sin(rotSpeed) + e->player.dir.y * cos(rotSpeed);
		double oldPlaneX = e->plane.x;
		e->plane.x = e->plane.x * cos(rotSpeed) - e->plane.y * sin(rotSpeed);
		e->plane.y = oldPlaneX * sin(rotSpeed) + e->plane.y * cos(rotSpeed);
	}
	draw(e);
	ContextToEnv(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
