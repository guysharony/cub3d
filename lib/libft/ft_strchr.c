/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:55:38 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:55:39 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = -1;
	while (++a < ft_strlen(s) + 1)
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
	return (NULL);
}
