#include "../includes/parser.h"

char	*command(int a)
{
	if (a == 0)
		return ("R ");
	else if (a == 1)
		return ("NO ");
	else if (a == 2)
		return ("SO ");
	else if (a == 3)
		return ("EA ");
	else if (a == 4)
		return ("WE ");
	else if (a == 5)
		return ("S ");
	else if (a == 6)
		return ("F ");
	else if (a == 7)
		return ("C ");
	return (NULL);
}

char	*startrm(char c, char *str)
{
	while (*str == c)
		str++;
	return (str);
}

int		startby(char *arg, char *line)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != line[i])
			return (0);
		i++;
	}
	return (1);
}

char	*startvalue(char *str)
{
	int		a;

	a = 0;
	while (a < 8)
	{
		if (startby(command(a), str))
			return (startrm(' ', str + ft_strlen(command(a))));
		a++;
	}
	return (NULL);
}