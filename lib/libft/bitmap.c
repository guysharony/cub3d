/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:16:14 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/23 11:17:50 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bitmap	set_bmp(int w, int h)
{
	int			i;
	t_bitmap	bmp;

	i = 0;
	while (i++ < 54)
		bmp.header[i] = 0;
	bmp.pi = w * sizeof(t_data);
	bmp.pa = (4 - (bmp.pi % 4)) % 4;
	bmp.header[0] = (unsigned char)'B';
	bmp.header[1] = (unsigned char)'M';
	*((unsigned int*)&bmp.header[2]) = 54 + (bmp.pi + bmp.pa) * h;
	bmp.header[10] = 54;
	bmp.header[14] = 40;
	*((unsigned int*)&bmp.header[18]) = w;
	*((unsigned int*)&bmp.header[22]) = h;
	bmp.header[26] = 1;
	bmp.header[28] = 24;
	bmp.width = w;
	bmp.height = h;
	return (bmp);
}

void		wrt_bmp(t_bitmap bmp, t_data **data, int fd)
{
	int		i;

	i = bmp.height;
	write(fd, bmp.header, 54);
	while (i-- > 0)
	{
		write(fd, data[i], bmp.pi);
		write(fd, "\0\0\0", bmp.pa);
	}
	close(fd);
}

int			make_bitmap(char *fn, int w, int h, t_data **data)
{
	int			fd;
	t_bitmap	bmp;

	fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC);
	bmp = set_bmp(w, h);
	wrt_bmp(bmp, data, fd);
	return (1);
}

int			bitmap(char *fn, int w, int h, int **data)
{
	t_data	**b;
	int		i;
	int		j;

	b = malloc_buf_data(w, h);
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < h; j++)
		{
			b[j][i].r = data[i][j] >> 16;
			b[j][i].g = (data[i][j] - (b[i][j].r << 16)) >> 8;
			b[j][i].b = data[i][j] - (b[i][j].r << 16) - (b[i][j].g << 8);
		}
	}
	make_bitmap(fn, w, h, b);
	clear_buf_data(&b, w);
	return (1);
}
