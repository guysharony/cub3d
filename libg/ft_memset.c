#include "libg.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*a;
	size_t				d;

	if (len == 0)
		return (b);
	a = (unsigned char *)b;
	d = 0;
	while (d < len)
		a[d++] = (unsigned char)c;
	return (b);
}