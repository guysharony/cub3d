#include "../includes/parser.h"

void	clean(t_file *content)
{
	int		a;

	a = 0;
	free(content->resolution);
	free(content->texture[0]);
	free(content->texture[1]);
	free(content->texture[2]);
	free(content->texture[3]);
	free(content->sprite);
	free(content->floor);
	free(content->ceiling);
	while (content->map[a] != NULL)
	{
		free(content->map[a]);
		a++;
	}
	free(content->map);
}

t_game		*parsefile(t_file *content)
{
	int		a;
	char	*str;
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	str = parsenumber(&game->R[0], content->resolution);
	parsenumber(&game->R[1], str);
	a = 0;
	game->T = malloc(sizeof(game->T) * 5);
	while (a < 5)
	{
		game->T[a] = malloc(sizeof(char) * (ft_strlen(content->texture[a]) + 1));
		ft_strcpy(game->T[a], content->texture[a]);
		a++;
	}
	game->T[a] = NULL;
	game->S = ft_strmcpy(content->sprite);
	parsecolor(&game->F[0], &game->F[1], &game->F[2], content->floor);
	parsecolor(&game->C[0], &game->C[1], &game->C[2], content->ceiling);
	parsemap(game, content->map);
	return (game);
}

char	*parsenumber(int *nb, char *str)
{
	int		a;

	a = 0;
	*nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= 48 && *str <= 57)
	{
		*nb *= 10;
		*nb += *str - 48;
		str++;
	}
	return (str);
}

char	*parsecolor(int *R, int *G, int *B, char *str)
{
	int		C[3];

	str = parsenumber(&C[0], str);
	str = parsenumber(&C[1], ft_strchr(str, ',') + 1);
	str = parsenumber(&C[2], ft_strchr(str, ',') + 1);
	*R = C[0];
	*G = C[1];
	*B = C[2];
	return (str);
}

void	parsemap(t_game *game, char **map)
{
	int		a;

	a = 0;
	
	game->map = malloc(sizeof(game->map) * (getmap_height(map) + 1));
	while (map[a] != NULL)
	{
		game->map[a] = getmap_line(map[a], getmap_width(map[a]));
		a++;
	}
	game->map[a] = NULL;
}
