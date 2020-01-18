/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:55:57 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:55:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;

	if (!(a = (char*)malloc(sizeof(*a) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(a, (char *)s1));
}
