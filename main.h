/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:45:43 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/07 12:33:20 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# define W 1500
# define H 800
# define AVERAGE(a, b) ((((a) ^ (b)) & 0xfffefefeL) >> 1) + ((a) & (b))

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

typedef struct		s_setup
{
	int				bpp;
	int				sl;
	int				endian;
	t_vector		camera;
}					t_setup;

typedef struct		s_ray
{
	t_vector		o;
	t_vector		d;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	t_setup			setup;
	unsigned int	*img_temp;
}					t_env;

void		ft_fill(t_env e, int w, int h, int color);
void		ft_text(t_env e, int w, int h, int color, char *str);
void		ft_event(t_env e, void *p);
void		samp(t_env *e);
t_ray		c_ray(t_vector i, t_vector j);
void		ray_trace(t_env *e);
t_vector	c_vector(int x, int y, int z);
void		create_img(t_env *e);
int			ft_key(int key, t_env *e);
int			ft_color(int r, int g, int b);

#endif
