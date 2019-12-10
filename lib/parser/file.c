#include "../includes/parser.h"

static void		ft_checker(t_file *content, char **str)
{
	char	*tmp;

	tmp = startvalue(*str);
	if (startby("R ", *str))
		content->resolution = ft_strmcpy(tmp);
	if (startby("NO ", *str))
		content->texture[0] = ft_strmcpy(tmp);
	if (startby("SO ", *str))
		content->texture[1] = ft_strmcpy(tmp);
	if (startby("EA ", *str))
		content->texture[3] = ft_strmcpy(tmp);
	if (startby("WE ", *str))
		content->texture[2] = ft_strmcpy(tmp);
	if (startby("S ", *str))
		content->sprite = ft_strmcpy(tmp);
	if (startby("F ", *str))
		content->floor = ft_strmcpy(tmp);
	if (startby("C ", *str))
		content->ceiling = ft_strmcpy(tmp);
}

static int		ft_height_map(char *name, int nb)
{
	int		a;
	int		file;
	int		res;
	char	*line;
	t_file	*content;

	a = 1;
	file = open(name, O_RDONLY);
	while ((res = get_next_line(file, &line)) >= 0)
	{
		free(line);
		if (a == nb - 1 || res == 0)
			break ;
		a++;
	}
	a = 0;
	while ((res = get_next_line(file, &line)) >= 0 && startby("1", line))
	{
		a++;
		free(line);
		if (res == 0)
			break ;
	}
	return (a);
}

static void		ft_getmap(t_file *content, char *name, int nb, int maph)
{
	int		a;
	int		file;
	int		res;
	char	*line;

	a = 1;
	file = open(name, O_RDONLY);
	while ((res = get_next_line(file, &line)) >= 0)
	{
		free(line);
		if (a == nb - 1 || res == 0)
			break ;
		a++;
	}
	content->map = malloc(sizeof(content->map) * (maph + 1));
	while ((res = get_next_line(file, &line)) >= 0)
	{
		content->map[a - nb + 1] = malloc(sizeof(char *) * ft_strlen(line));
		ft_strcpy(content->map[a - nb + 1], line);
		a++;
		free(line);
		if (res == 0)
			break ;
	}
	content->map[a - nb + 1] = NULL;
}

t_file		*getfile(char *name)
{
	int		a;
	int		file;
	int		res;
	char	*line;
	t_file	*content;

	a = 1;
	file = open(name, O_RDONLY);
	content = (t_file *)malloc(sizeof(t_file));
	while ((res = get_next_line(file, &line)) > 0)
	{
		if (!startby("1", line))
			ft_checker(content, &line);
		else
		{
			ft_getmap(content, name, a, ft_height_map(name, a));
			free(line);
			break ;
		}
		a++;
		free(line);
	}
	return (content);
}