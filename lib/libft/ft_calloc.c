#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (!(a = malloc(count * size)))
		return (NULL);
	if (a)
		ft_bzero(a, count * size);
	return (a);
}