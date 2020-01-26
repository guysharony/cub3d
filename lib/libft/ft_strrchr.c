/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:57:06 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:57:07 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;

	a = ft_strlen(s) + 1;
	while (a--)
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
	return (NULL);
}
