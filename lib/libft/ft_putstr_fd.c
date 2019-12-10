#include "../includes/libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	int		a;

	a = 0;
	while (str[a])
	{
		ft_putchar_fd(fd, str[a]);
		a++;
	}
}