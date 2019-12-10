#include "../includes/libft.h"

char	*ft_strmcpy(char *str)
{
	char	*dst;

	dst = ft_calloc(sizeof(str), ft_strlen(str) + 1);
	ft_strcpy(dst, str);
	return (dst);
}