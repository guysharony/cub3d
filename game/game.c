/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 13:15:16 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

double	*malloc_zbuf(int x)
{
	double		*zbuf;

	zbuf = malloc(sizeof(zbuf) * x);
	return (zbuf);
}

int		**malloc_buf(int x, int y)
{
	int		**buf;
	int		i;

	i = 0;
	buf = malloc(sizeof(*buf) * x);
	while (i < x)
	{
		buf[i] = malloc(sizeof(buf) * y);
		i++;
	}
	return (buf);
}

void	mkimage(t_env *e)
{
	int			x;
	int			y;
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
		drawlinebuffer(e, x, 0, x, e->resolution[1] - 1, buf[x]);
}

void	draw(t_env *e)
{
	int			x;
	int			y;

	createenv(e);
	free(e->img_temp);
	createcontext(e);
	contexttoenv(e);
	mkimage(e);
}
