#include "../includes/parser.h"

int		getmap_height(char **map)
{
	int		a;

	a = 0;
	while (map[a] != NULL)
		a++;
	return (a);
}

int		getmap_width(char *map)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (map[a])
	{
		if (map[a] == '0' || map[a] == '1' || map[a] == '2' || map[a] == 'N' ||
				map[a] == 'S' || map[a] == 'E' || map[a] == 'W' || map[a] == ' ')
		{
			if (map[a] == '0' || map[a] == '1' || map[a] == '2' || map[a] == 'N' ||
				map[a] == 'S' || map[a] == 'E' || map[a] == 'W')
				b++;
			a++;
		}
		else
			return (-1);
	}
	return (b);
}

char	*getmap_line(char *line, int length)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	str = malloc(sizeof(char *) * (length + 1));
	while (line[a])
	{
		if (line[a] == '0' || line[a] == '1' || line[a] == '2' || line[a] == 'N' ||
				line[a] == 'S' || line[a] == 'E' || line[a] == 'W' || line[a] == ' ')
		{
			if (line[a] == '0' || line[a] == '1' || line[a] == '2' || line[a] == 'N' ||
				line[a] == 'S' || line[a] == 'E' || line[a] == 'W')
			{
				str[b] = line[a];
				b++;
			}
			a++;
		}
		else
			return (NULL);
	}
	str[b] = '\0';
	return (str);
}
