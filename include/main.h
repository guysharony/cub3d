/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:45 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/01 11:53:26 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libg/libg.h"
# define W 640
# define H 480
# define abs(x) (x > 0 ? x : -x)
# define mapWidth 24
# define mapHeight 24
# define texWidth 64
# define texHeight 64

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_coo
{
	double			x;
	double			y;
}					t_coo;

typedef struct		s_object
{
	t_coo			pos;
	t_coo			dir;
}					t_object;

typedef struct		s_setup
{
	int				bpp;
	int				sl;
	int				endian;
}					t_setup;

typedef struct		s_keys
{
	int				t_13;
	int				t_1;
	int				t_0;
	int				t_2;
	int				t_123;
	int				t_124;
}					t_keys;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	t_setup			setup;
	t_object		player;
	t_coo			plane;
	void			*texture[4];
	char			*textureD[4];
	t_setup			textureS[4];
	t_keys			keys;
	char			**map;
	unsigned int	*img_temp;
}					t_env;

t_coo	sld_int(t_env *e, t_pos map, t_coo dlt, t_coo ray);
t_coo	ray_dir(t_env *e, double cameraX);
t_coo	dlt_dst(t_env *e, t_coo ray);
t_pos	map_pos(t_env *e);
t_pos	stp_int(t_coo ray);

void			get_texture(t_env *e);
t_vector		c_vector(int x, int y, int z);
t_env			*EnvInit(char **av);
int				ft_color(int r, int g, int b);
int				move(t_env *e);
int				Exit(t_env *e);
int				KeyDown(int key, t_env *e);
int				KeyUp(int key, t_env *e);
void			draw(t_env *e);
void			CreateEnv(t_env *e);
void			CreateContext(t_env *e);
void			DrawLine(t_env *e, int x1, int y1, int x2, int y2, int color);
void			DrawLineBuffer(t_env *e, int x1, int y1, int x2, int y2, int bff[]);
void			DrawTriangle(t_env *e, int x1, int y1, int x2, int y2, int x3, int y3, int color);
void			ContextToEnv(t_env *e);
void			EnvToWindow(t_env *e, int x, int y);

#endif
