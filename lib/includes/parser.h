/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:46:09 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/20 09:50:26 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct		s_texture
{
	char			**north;
	char			**south;
	char			**east;
	char			**west;
	char			**sprite;
}					t_texture;

typedef struct		s_player
{
	char			direction;
	int				posx;
	int				posy;
}					t_player;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_sprite
{
	int				size;
	t_pos			*sprite;
}					t_sprite;

typedef struct		s_map
{
	char			**map;
	int				height;
}					t_map;

typedef struct		s_game
{
	char			**resolution;
	char			**ceiling;
	char			**floor;
	t_player		*player;
	t_sprite		*sprite;
	t_texture		*wall;
	t_map			*map;
}					t_game;

int					parsecommands(t_game *game, char *map);
int					parsemap(t_game *game, char *map);
int					parse(t_game *game, char *filename);
void				ft_clean(t_game *game);

void				getmap_height(t_game *game, char *map);
char				*getmap_line(char *line, int length);
int					getmap_width(char *map);
void				gameinit(t_game *game);

int					check(t_game *game, int file);
int					checkwalls(t_game *game);
int					checkresolution(char **resolution);
int					checkplayer(t_game *game);
int					checkplayerdef(t_game *game);
int					checkfiles(t_game *game);
int					checkend(int file);
int					checkcolor(char **color);
int					checkblocks(t_game *game);
int					checkargnum(char **arg, int nb);
int					checkmap(t_game *game);

#endif
