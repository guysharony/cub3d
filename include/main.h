/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:14:45 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:22:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "../lib/lib.h"

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

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
	t_pos			size;
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

typedef struct		s_draw_wall
{
	int				sde;
	int				lnh;
	int				clr;
	double			cam;
	double			wll;
	t_coo			ray;
	t_coo			sld;
	t_coo			dlt;
	t_pos			drw;
	t_pos			map;
	t_pos			stp;
}					t_draw_wall;

typedef struct		s_draw_sprite
{
	int				screenx;
	double			invdet;
	t_coo			sprite;
	t_coo			transform;
	t_pos			size;
	t_pos			drawx;
	t_pos			drawy;
}					t_draw_sprite;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				resolution[3];
	int				floor[3];
	int				ceiling[3];
	char			mapc;
	char			*data;
	t_setup			setup;
	t_object		player;
	t_coo			plane;
	void			*texture[5];
	char			*textured[5];
	t_setup			textures[5];
	t_keys			keys;
	t_game			*game;
	unsigned int	*img_temp;
}					t_env;

t_coo				sld_int(t_env *e, t_pos map, t_coo dlt, t_coo ray);
t_coo				ray_dir(t_env *e, double camerax);
t_coo				dlt_dst(t_coo ray);
t_pos				map_pos(t_env *e);
t_pos				stp_int(t_coo ray);

void				get_texture(t_env *e);
void				get_texture_north(t_env *e);
void				get_texture_south(t_env *e);
void				get_texture_east(t_env *e);
void				get_texture_west(t_env *e);
void				get_texture_sprite(t_env *e);

void				set_world(t_env *e, int save);
void				set_resolution(t_env *e);
void				set_player(t_env *e);
void				set_data(t_env *e, char *filename);
void				set_colors(t_env *e);

void				move_forward(t_env *e, double movespeed);
void				move_backward(t_env *e, double movespeed);
void				move_left(t_env *e, double movespeed);
void				move_right(t_env *e, double movespeed);
void				rotate_left(t_env *e, double rotspeed);
void				rotate_right(t_env *e, double rotspeed);

t_pos				map_pos(t_env *e);
t_coo				ray_dir(t_env *e, double camerax);
t_coo				sld_int(t_env *e, t_pos map, t_coo dlt, t_coo ray);
t_pos				stp_int(t_coo ray);
t_pos				get_stp(t_coo ray);
t_coo				get_sld(t_env *e, t_coo ray, t_coo dlt, t_pos map);
t_draw_wall			set_hit(t_env *e, t_draw_wall draw);
void				set_draw_wall(t_env *e, int x, int ***buf, double **zbuf);
void				set_draw_sprt(t_env *e, int x, int ***buf, double **zbuf);
double				compute_wall(t_env *e, t_draw_wall draw);
double				compute_sprite(t_env *e, t_draw_wall draw);
double				get_wallx(t_env *e, t_draw_wall draw);
int					get_texture_posx(t_env *e, t_draw_wall draw, int i);
int					get_wallc(t_env *e, t_draw_wall draw, int dy);
t_coo				spt_transform(t_env *e, t_draw_sprite draw);
t_pos				spt_size(t_env *e, t_draw_sprite draw);
t_coo				spt_pos(t_env *e, int x);
t_pos				spt_texture(t_env *e, t_draw_sprite draw, int i, int d);
t_pos				spt_draw_x(t_env *e, t_draw_sprite draw);
t_pos				spt_draw_y(t_env *e, t_draw_sprite draw);
int					spt_screenx(t_env *e, t_draw_sprite draw);
double				spt_invdet(t_env *e);

t_vector			c_vector(int x, int y, int z);
t_env				*envinit(char **av, int save);
int					ft_color(int r, int g, int b);
int					move(t_env *e);
int					exitgame(t_env *e);
int					keydown(int key, t_env *e);
int					keyup(int key, t_env *e);
void				draw(t_env *e, int save);
void				createenv(t_env *e);
void				createcontext(t_env *e);
void				drawlinebuffer(t_env *e, int x1, int bff[]);
void				contexttoenv(t_env *e);
void				envtowindow(t_env *e, int x, int y);

#endif
