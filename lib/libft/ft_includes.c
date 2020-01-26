/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:50:06 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:52:40 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strincludes(char *str1, char *str2)
{
	int		a;

	a = 0;
	while (str1[a])
	{
		if (!ft_includes(str1[a], str2))
			return (0);
		a++;
	}
	return (1);
}

int		ft_includes(char c, char *str)
{
	int		a;

	a = 0;
	while (str[a])
	{
		if (c == str[a])
			return (1);
		a++;
	}
	return (0);
}
