/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:55:20 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:23:05 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_lstlength(char **lst)
{
	int		a;

	a = 0;
	while (lst[a] != NULL)
		a++;
	return (a);
}

char			**parsecolor(char *data)
{
	char	**color;

	color = ft_split(data, ',');
	return (color);
}
