#include "../includes/libft.h"

void	ft_putnbr_fd(int fd, int nb)
{
	if (nb == -2147483648)
		return (ft_putstr_fd(fd, "-2147483648"));
	if (nb < 0)
	{
		ft_putchar_fd(fd, '-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(fd, nb / 10);
		ft_putnbr_fd(fd, nb % 10);
	}
	else
		ft_putchar_fd(fd, nb + '0');
}