/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:56:45 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:56:46 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while (s1[n] || s2[n])
		n++;
	return (ft_strncmp(s1, s2, n));
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n - 1 && s1[a] && s1[a] == s2[a])
		a++;
	if (n)
		return (*((unsigned char *)s1 + a) - *((unsigned char *)s2 + a));
	return (0);
}
