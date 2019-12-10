#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct		s_game
{
	int				R[2];
	char			**T;
	char			*S;
	int				F[3];
	int				C[3];
	char			**map;
	int				status;
}					t_game;

typedef struct		s_file
{
	char			*resolution;
	char			*texture[4];
	char			*sprite;
	char			*floor;
	char			*ceiling;
	char			**map;
}					t_file;

char		*getmap_line(char *line, int length);
int			getmap_width(char *map);
int			getmap_height(char **map);

char		*startrm(char c, char *str);
int			startby(char *arg, char *line);
char		*startvalue(char *str);
char		*command(int a);

int			parsemap(t_game *game, char **map);
char		*parsecolor(int *R, int *G, int *B, char *str);
char		*parsenumber(int *nb, char *str);

t_file		*getfile(char *name);
t_game		*parsefile(t_file *content);
void		clean(t_file *content);
int			check_map(char **map, int height);

#endif
