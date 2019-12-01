#include "libg.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

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