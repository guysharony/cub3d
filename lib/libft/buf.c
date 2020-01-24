/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:08:35 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 09:10:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			**malloc_buf(int x, int y)
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

t_data		**malloc_buf_data(int x, int y)
{
	t_data		**buf;
	int			i;

	i = 0;
	buf = malloc(sizeof(*buf) * x);
	while (i < x)
	{
		buf[i] = malloc(sizeof(buf) * y);
		i++;
	}
	return (buf);
}

void		clear_buf_data(t_data ***buf, int h)
{
	int		i;

	i = 0;
	while (i < h)
	{
		free((*buf)[i]);
		i++;
	}
	free((*buf));
}
