/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:53:34 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:53:37 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
