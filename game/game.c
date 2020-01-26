/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:47:56 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

double	*malloc_zbuf(int x)
{
	double		*zbuf;

	zbuf = malloc(sizeof(zbuf) * x);
	return (zbuf);
}

void	clear_buf(int ***buf, t_env *e)
{
	int		i;

	i = 0;
	while (i < e->resolution[0])
	{
		free((*buf)[i]);
		i++;
	}
	free((*buf));
}

void	mkimage(t_env *e, int save)
{
	int			x;
	int			**buf;
	double		*zbuf;

	x = -1;
	zbuf = malloc_zbuf(e->resolution[0]);
	buf = malloc_buf(e->resolution[0], e->resolution[1]);
	while (++x < e->resolution[0])
		set_draw_wall(e, x, &buf, &zbuf);
	x = -1;
	while (++x < e->game->sprite->size)
		set_draw_sprt(e, x, &buf, &zbuf);
	x = -1;
	while (++x < e->resolution[0])
		drawlinebuffer(e, x, buf[x]);
	if (save == 1)
		bitmap("cub3D.bmp", e->resolution[0], e->resolution[1], buf);
	free(zbuf);
	clear_buf(&buf, e);
}

void	draw(t_env *e, int save)
{
	mlx_destroy_image(e->mlx, e->img);
	createenv(e);
	free(e->img_temp);
	createcontext(e);
	contexttoenv(e);
	mkimage(e, save);
}
